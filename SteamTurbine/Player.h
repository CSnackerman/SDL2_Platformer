#pragma once

#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_log.h>

#include "Vec2.h"

enum class Direction { LEFT, RIGHT, NONE };

class Player
{
public:
	
	// data
	Vec2 position;
	Vec2 velocity;
	Vec2 acceleration;

	SDL_Rect rect;
	Uint8 r,g,b,a;

	// functions
	Player ();

	void move (Direction d);

	void update (float dt);

	void draw (SDL_Renderer* renderer);

	void bindRect ();

};

