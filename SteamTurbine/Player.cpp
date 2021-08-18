#include "Player.h"

Player::Player() {
	
	position = Vec2 (0, 0);
	velocity = Vec2 (0, 0);
	acceleration = Vec2 (0, 0);

	rect.x = position.x;
	rect.y = position.y;
	rect.w = 25;
	rect.h = 50;

	r = 173;
	g = 72;
	b = 199;
	a = 255;
}

void Player::move(Direction d) {
	
	switch (d) {

		case Direction::LEFT:
			acceleration.x = -10.0f;
			break;


		case Direction::RIGHT:
			acceleration.x = 10.0f;
			break;

		case Direction::NONE:
			acceleration.x = 0;
			velocity.x = 0;
			break;
	}
}

void Player::update(float dt) {
	acceleration.x = acceleration.x * dt;
	acceleration.y = acceleration.y * dt;
	velocity = velocity + acceleration;
	position = position + velocity;
	bindRect();
	SDL_Log("%f, %f", acceleration.x, acceleration.y);
}


void Player::draw(SDL_Renderer* renderer) {
	
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderFillRect(renderer, &rect);
}


void Player::bindRect() {

	rect.x = position.x;
	rect.y = position.y;
	
	return;
}