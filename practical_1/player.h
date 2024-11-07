#pragma once
#include "entity.h"
#include "game.h"

class Player : public Entity {
	public:
		float _speed;

		Player();
		void Update(double dt) override;
		void Render(sf::RenderWindow& window) const override;
};