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

/*
void drawButton(SkCanvas* canvas) {
    canvas->save();
    canvas->translate(SkIntToScalar(128), SkIntToScalar(128));
    SkRect rect = SkRect::MakeXYWH(-90.5f, -90.5f, 181.0f, 181.0f);
    SkRRect rrect;
    rrect.setRectXY(rect, 20, 20);

    SkPaint paint;
    paint.setColor(SK_ColorBLUE);
    canvas->drawRect(rect, paint);
    paint.setColor(SK_ColorRED);
    paint.setAntiAlias(true);
    canvas->translate(SkIntToScalar(190), SkIntToScalar(190));
    canvas->drawRRect(rrect, paint);
    paint.setColor(SK_ColorBLACK);
    canvas->translate(SkIntToScalar(10), SkIntToScalar(45));
    canvas->drawText("appels", strlen("appels"), SkIntToScalar(0),
                         SkIntToScalar(0), paint);
    canvas->restore();
}
*/


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
            default:
                break;
        }
    }
}


int main(int argc, char** argv) {

    uint32_t windowFlags = 0;

    kobu::Vec2 button_pos;
    kobu::YRect clip_region;
    kobu::Vec2 test1, test2;



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
    static const int kMsaaSampleCount = 4; //4;
    // SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    // SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, kMsaaSampleCount);

    /*
     * In a real application you might want to initialize more subsystems
     */
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        handle_error();
        return 1;
    }



    SDL_DisplayMode dm;
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
    SkAutoTUnref<GrContext> grContext(GrContext::Create(kOpenGL_GrBackend,
                                                        (GrBackendContext)interface.get()));
    SkASSERT(grContext);


    // Wrap the frame buffer object attached to the screen in a Skia render target so Skia can
    // render to it
    GrBackendRenderTargetDesc desc;
    desc.fWidth = dm.w;
    desc.fHeight = dm.h;
    desc.fConfig = kSkia8888_GrPixelConfig;
    desc.fOrigin = kBottomLeft_GrSurfaceOrigin;
    desc.fSampleCnt = kMsaaSampleCount;
    desc.fStencilBits = kStencilBits;
    GrGLint buffer;
    GR_GL_GetIntegerv(interface, GR_GL_FRAMEBUFFER_BINDING, &buffer);
    desc.fRenderTargetHandle = buffer;
    SkSurfaceProps props(SkSurfaceProps::kUseDeviceIndependentFonts_Flag, SkSurfaceProps::kLegacyFontHost_InitType);


    //SkSurfaceProps props(SkSurfaceProps::kLegacyFontHost_InitType);

    sk_sp<SkSurface> surface(SkSurface::MakeFromBackendRenderTarget(grContext, desc, &props));

    SkCanvas* canvas = surface->getCanvas();

    graphics = new kobu::YGraphics(surface->getCanvas());

    /* KOBU STUFF */
    clip_region.x = 200.0;
    clip_region.y = 200.0;
    clip_region.w = 400.0;
    clip_region.h = 400.0;

    test1.x = 0.0;
    test1.y = 0.0;
    test2.x = 100.0;
    test2.y = 100.0;


    button_pos.x = button_pos.y = 400.0;
    std::string appelsap = "Appelsap";
    button = new kobu::YButton(appelsap, button_pos);
    container = new kobu::YGuiContainer(clip_region);
    container->AddWidget(button);

    
    /* END KOBU */
    ApplicationState state;

    //const char* helpMessage = "Click and drag to create rects.  Press esc to quit.";

    SkPaint paint;

    // create a surface for CPU rasterization
    sk_sp<SkSurface> cpuSurface(SkSurface::MakeRaster(canvas->imageInfo()));
/*
    SkCanvas* offscreen = cpuSurface->getCanvas();
    offscreen->save();
    offscreen->translate(50.0f, 50.0f);
    offscreen->drawPath(create_star(), paint);
    offscreen->restore();
*/
    sk_sp<SkImage> image = cpuSurface->makeImageSnapshot();

    //int rotation = 0;
 
    while (!state.fQuit) { // Our application loop
        
        SkRandom rand;
        canvas->clear(SK_ColorWHITE);
        handle_events(&state, canvas);
        /*
        paint.setColor(SK_ColorBLACK);
        paint.setAntiAlias(true);
        canvas->drawText(helpMessage, strlen(helpMessage), SkIntToScalar(100),
                         SkIntToScalar(100), paint);
        paint.setAntiAlias(false);
        canvas->drawText(helpMessage, strlen(helpMessage), SkIntToScalar(100),
                         SkIntToScalar(120), paint);

        canvas->save();
        for (int i = 0; i < state.fRects.count(); i++) {
            paint.setColor(rand.nextU() | 0x44808080);
            canvas->drawRect(state.fRects[i], paint);
        }
        canvas->restore();
        container->Draw(graphics);
        */
        canvas->save();
        canvas->translate(0.0, 50.0);
            graphics->DrawRoundRect(0xFF00FF00, test1, test2, 10.0);
        //drawButton(canvas);
        /*
        graphics->DrawRoundRect(kobu::Y2DCoord(10, 100), 
            kobu::Y2DCoord(100,100), 10);
        graphics->DrawText("Splop", kobu::Y2DCoord(300, 300));
        */
        // draw offscreen canvas
        /*
        canvas->save();
        canvas->translate(dm.w / 2.0, dm.h / 2.0);
        canvas->rotate(rotation++);
        canvas->drawImage(image, -50.0f, -50.0f);
        canvas->restore();
        */
        canvas->restore();
        canvas->flush();
        SDL_GL_SwapWindow(window);
    }

    if (glContext) {
        SDL_GL_DeleteContext(glContext);
    }

    delete button;
    delete container;

    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();
    return 0;
}









