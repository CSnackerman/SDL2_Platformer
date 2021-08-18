#include <iostream>
#include <string>

#include <SDL.h>
#include <box2d.h>

#include "Player.h"

//Screen dimension constants
constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;


// prototypes ( function declarations )
bool init();
void close();
void handleEvents(SDL_Event& e, Player& player, bool& quit);


//The window we'll be rendering to
SDL_Window* gWindow = NULL;
	
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;


SDL_Renderer* renderer = NULL;



void close()
{
	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}


int main ( int argc, char* args[] )
{
	
	// Setup
	SDL_Init(SDL_INIT_EVERYTHING);

	gWindow = SDL_CreateWindow (
		"SDL Tutorial",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN
	);

	gScreenSurface = SDL_GetWindowSurface(gWindow);

	renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);


	// runtime variable declarations
	bool quit = false;
	SDL_Event e;

	// time
	float dt = 0;
	Uint32 ticks = SDL_GetTicks();
	Uint32 prevTicks = ticks;

	// Objects
	Player player;

	// Running
	while( !quit )
	{	
		// time / frames
		ticks = SDL_GetTicks();
		dt = (float) (ticks - prevTicks) / 1000.0f;
		prevTicks = ticks;
		
		// events
		handleEvents(e, player, quit);

		// Clear the frame buffer
		SDL_SetRenderDrawColor (renderer, 50, 168, 133, 255);
		SDL_RenderClear(renderer);

		// Update game objects
		player.update(dt);

		// Draw game objects
		player.draw (renderer);
			
		// Update the surface
		SDL_RenderPresent (renderer);
	}

	//Free resources and close SDL
	close();

	return 0;
}





// ----------------------------------------------------------------------------

void handleEvents(SDL_Event& e, Player &player, bool& quit) 
{
	while (SDL_PollEvent(&e) != 0)
	{

		// key is PRESSED
		if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {

			// UP
			if (e.key.keysym.sym == SDLK_UP) {
				std::cout << "UP pressed" << std::endl;
			}

			// DOWN
			else if (e.key.keysym.sym == SDLK_DOWN) {
				std::cout << "DOWN pressed" << std::endl;
			}
		}

		// key is RELEASED
		else if (e.type == SDL_KEYUP) {
			
			// UP
			if (e.key.keysym.sym == SDLK_UP) {
				std::cout << "UP released" << std::endl;
			}

			// DOWN
			else if (e.key.keysym.sym == SDLK_DOWN) {
				std::cout << "DOWN released" << std::endl;
			}
		}

		// quit
		else if (e.type == SDL_QUIT) {
			quit = true;
			break;
		}
	}

	// Get keyboard state
	const Uint8* keys = SDL_GetKeyboardState(NULL);

	if (keys[SDL_SCANCODE_LEFT]) {
		std::cout << "holding LEFT" << std::endl;
		player.move (Direction::LEFT);
	}

	if (keys[SDL_SCANCODE_RIGHT]) {
		std::cout << "holding RIGHT" << std::endl;
		player.move (Direction::RIGHT);
	}

	if (!keys[SDL_SCANCODE_LEFT] && !keys[SDL_SCANCODE_RIGHT]) {
		player.move(Direction::NONE);
	}
}