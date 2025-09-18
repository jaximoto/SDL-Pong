#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "GameState/GameState.hpp"
#include "GameObjects/DrawableGameObject.hpp"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>


const char* title = "Pong";
const char* version = "1.0";
const char* identifier = "com.Pong.Real-Time";

const int screenWidth = 1920;
const int screenHeight = 1080;
const int logicalWidth = 640;
const int logicalHeight = 360;
bool debug = true;
/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
	// Enable run-time memory check for debug builds.
    if (debug)
    {
        _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    }
    
   
    SDL_SetAppMetadata(title, version, identifier);

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

	GameState* gameState = new GameState(title, screenWidth, screenHeight, logicalWidth, logicalHeight, false);
    
	DrawableGameObject* box = new DrawableGameObject(100, 100, 50, 50, 1, Color::Green);

    DrawableGameObject* box1 = new DrawableGameObject(200, 50, 50, 50, 1, Color::Red);

    DrawableGameObject* box2 = new DrawableGameObject(300, 0, 50, 50, 1, Color::Blue);

	gameState->renderManager->AddObject(box);
    gameState->renderManager->AddObject(box1);
    gameState->renderManager->AddObject(box2);

	*appstate = gameState;
    /*
    if (!SDL_CreateWindowAndRenderer("examples/renderer/clear", 640, 480, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    */
    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }

    if (event->type == SDL_EVENT_KEY_DOWN) {
        const SDL_KeyboardEvent* keyEvent = (const SDL_KeyboardEvent*)event;
        if (keyEvent->key == SDLK_ESCAPE)
            return SDL_APP_SUCCESS;
    }
    
    


    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void* appstate)
{
    
	GameState* gameState = static_cast<GameState*>(appstate);

	gameState->renderManager->Render();

	

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    /* SDL will clean up the window/renderer for us. */
	GameState* gameState = static_cast<GameState*>(appstate);
    delete gameState;
	SDL_Quit();
    

}
