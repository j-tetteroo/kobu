#include <iostream>

#include "GrContext.h"
#include "SDL.h"
#include "SkCanvas.h"
#include "SkSurface.h"
#include "SkRRect.h"

#include "gl/GrGLInterface.h"
#include "gl/GrGLUtil.h"
#include <GL/gl.h>

#include "core/YGraphics.h"
#include "widgets/YButton.h"
#include "events/YMouseEvent.h"
#include "window/YGuiContainer.h"
#include "util/YTypes.h"


kobu::YGraphics *graphics;
kobu::YButton *button;
kobu::YGuiContainer *container;

        SDL_DisplayMode dm;
        sk_sp<SkSurface> surface;
        GrBackendRenderTargetDesc desc;
        GrContext *grContext;
        SkSurfaceProps *p;

struct ApplicationState {
    ApplicationState() : fQuit(false) {}
    // Storage for the user created rectangles. The last one may still be being edited.
    SkTArray<SkRect> fRects;
    kobu::YGuiContainer *container;


    bool fQuit;
};

static void handle_error() {
    const char* error = SDL_GetError();
    SkDebugf("SDL Error: %s\n", error);
    SDL_ClearError();
}


static void handle_events(ApplicationState* state, SkCanvas* canvas) {
    SDL_Event event;
    kobu::Vec2 coords;
    kobu::YMouseEvent *me;

    while(SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_MOUSEMOTION:
                if (event.motion.state == SDL_PRESSED) {
                    SkRect& rect = state->fRects.back();
                    rect.fRight = event.motion.x;
                    rect.fBottom = event.motion.y;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.state == SDL_PRESSED) {
                    state->fRects.push_back() = SkRect::MakeLTRB(SkIntToScalar(event.button.x),
                                                                 SkIntToScalar(event.button.y),
                                                                 SkIntToScalar(event.button.x),
                                                                 SkIntToScalar(event.button.y));
                }

                coords.x = event.button.x;
                coords.y = event.button.y;
                std::cout << event.button.x << " " << event.button.y << "\n";
                me = new kobu::YMouseEvent(coords, kobu::MouseEventType::M_DOWN , kobu::MouseButton::M_LEFT);
                container->TriggerEvent((kobu::YEvent *)me);
                delete me;
                
                
                break;
            case SDL_MOUSEBUTTONUP:
                coords.x = event.button.x;
                coords.y = event.button.y;
                me = new kobu::YMouseEvent(coords, kobu::MouseEventType::M_UP , kobu::MouseButton::M_LEFT);
                container->TriggerEvent((kobu::YEvent *)me);
                delete me;
                break;
            case SDL_KEYDOWN: {
                SDL_Keycode key = event.key.keysym.sym;
                if (key == SDLK_ESCAPE) {
                    state->fQuit = true;
                }
                break;
            }
            case SDL_QUIT:
                state->fQuit = true;
                break;
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    dm.w = event.window.data1;
                    dm.h = event.window.data2;

                    desc.fWidth = dm.w;
                    desc.fHeight = dm.h;

                    glViewport(0, 0, dm.w, dm.h);
                    surface.reset();
                    surface = SkSurface::MakeFromBackendRenderTarget((GrContext*)grContext, desc, p);
                    //std::cout << "RESIZE" << "\n";
                }
                break;
            default:
                break;
        }
    }
}


int main(int argc, char** argv) {

    uint32_t windowFlags = 0;

    kobu::Vec2 button_pos;
    kobu::YRect clip_region;
    //kobu::Vec2 test1, test2;



    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    SDL_GLContext glContext = nullptr;
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    windowFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;

    static const int kStencilBits = 8;  // Skia needs 8 stencil bits
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, kStencilBits);

    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

    // If you want multisampling, uncomment the below lines and set a sample count
    static const int kMsaaSampleCount = 0; //4;
    // SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    // SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, kMsaaSampleCount);

    /*
     * In a real application you might want to initialize more subsystems
     */
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        handle_error();
        return 1;
    }


    if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
        handle_error();
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, dm.w, dm.h, windowFlags);

    if (!window) {
        handle_error();
        return 1;
    }


    glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        handle_error();
        return 1;
    }

    int success =  SDL_GL_MakeCurrent(window, glContext);
    if (success != 0) {
        handle_error();
        return success;
    }

    glViewport(0, 0, dm.w, dm.h);
    glClearColor(1, 1, 1, 1);
    glClearStencil(0);
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);


    // setup GrContext
    SkAutoTUnref<const GrGLInterface> interface(GrGLCreateNativeInterface());

    // To use NVPR, comment this out
    interface.reset(GrGLInterfaceRemoveNVPR(interface));
    SkASSERT(interface);

    // setup contexts
    grContext = GrContext::Create(kOpenGL_GrBackend, (GrBackendContext)interface.get());
    SkASSERT(grContext);


    // Wrap the frame buffer object attached to the screen in a Skia render target so Skia can
    // render to it

    desc.fWidth = dm.w;
    desc.fHeight = dm.h;
    desc.fConfig = kSkia8888_GrPixelConfig;
    desc.fOrigin = kBottomLeft_GrSurfaceOrigin;
    desc.fSampleCnt = kMsaaSampleCount;
    desc.fStencilBits = kStencilBits;
    GrGLint buffer;
    GR_GL_GetIntegerv(interface, GR_GL_FRAMEBUFFER_BINDING, &buffer);
    desc.fRenderTargetHandle = buffer;
    p = new SkSurfaceProps(SkSurfaceProps::kUseDeviceIndependentFonts_Flag, SkSurfaceProps::kLegacyFontHost_InitType);


    //SkSurfaceProps props(SkSurfaceProps::kLegacyFontHost_InitType);

    surface = SkSurface::MakeFromBackendRenderTarget((GrContext*)grContext, desc, p);

    SkCanvas* canvas = surface->getCanvas();

    graphics = new kobu::YGraphics(surface->getCanvas());

    /* KOBU STUFF */
    clip_region.x = 200.0;
    clip_region.y = 200.0;
    clip_region.w = 400.0;
    clip_region.h = 400.0;

    /*
    test1.x = 0.0;
    test1.y = 0.0;
    test2.x = 100.0;
    test2.y = 100.0;
    */

    button_pos.x = button_pos.y = 400.0;
    std::string appelsap = "Appelsap";

    button = new kobu::YButton(appelsap, button_pos);
    kobu::YButton *button2 = new kobu::YButton("flopsaaa", 0xFF00FF00, 300.0, 300.0);

    container = new kobu::YGuiContainer(clip_region);
    container->AddWidget(button);
    container->AddWidget(button2);

    
    /* END KOBU */
    ApplicationState state;


    SkPaint paint;

    // Main Loop 
    while (!state.fQuit) { // Our application loop
        handle_events(&state, canvas);

        canvas = surface->getCanvas();
        graphics->SetCanvas(canvas);

        canvas->clear(SK_ColorWHITE);


        canvas->save();

        //graphics->DrawRoundRect(0xFF00FF00, test1, test2, 10.0);
        container->Draw(graphics);

        canvas->restore();
        canvas->flush();
        SDL_GL_SwapWindow(window);
    }

    if (glContext) {
        SDL_GL_DeleteContext(glContext);
    }

    delete button;
    delete button2;
    delete container;
    delete graphics;
    //delete surface;
    //grContext.reset();
    //delete grContext;

    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();
    return 0;
}









