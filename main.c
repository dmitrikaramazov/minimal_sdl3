#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

static SDL_Window *window = nullptr;
static SDL_Renderer *renderer = nullptr;
static char* window_name = "Minimal SDL3 window";

typedef struct {
    // 
} AppState;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]){
    if(!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    if(!SDL_CreateWindowAndRenderer(window_name, 640, 480, 0, &window, &renderer)){
        SDL_Log("Couldn't initialize window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    AppState *state = (AppState*)SDL_calloc(1, sizeof(AppState));
    *appstate = state;
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event *event){
    AppState* state = (AppState*) appstate;
    if(event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }
    if(event->type == SDL_EVENT_KEY_DOWN) {
        switch(event->key.key) {
            case SDLK_ESCAPE:
                return SDL_APP_SUCCESS;
                break;
            default:
                break;
        }
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate){
    const double now = ((double)SDL_GetTicks()) / 1000.0;
    const float color = (float) (0.5 + 0.5 * SDL_sin(now));
    const float red = color, blue = color / 2.0, green = color / 4.0;
    SDL_SetRenderDrawColorFloat(renderer,red,green,blue, SDL_ALPHA_OPAQUE_FLOAT);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return;
}