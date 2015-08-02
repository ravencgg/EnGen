#pragma once

#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>
#include "types.h"
#include "Entity.h"

class Scene
{

public:
	Scene();
	virtual ~Scene();

	// Calls all of the updates in the entities vector
	virtual void Update(float) = 0;

	// Draws all of the sprites in the sprites vector
	virtual void Render(sf::RenderWindow*) = 0;

	// Takes possession of the pointer
	void AddEntity(Entity*);

	// Shares the pointer
    // NOTE(cgenova): Just add to the correct list and never worry about sorting.
	void AddDrawable(std::shared_ptr<sf::Sprite>, DrawLayer::Enum);

protected:

	// Consider making this a more polymorphic array
	std::vector<std::shared_ptr<sf::Sprite>> sprites[DrawLayer::LAYER_COUNT];
	std::vector<std::unique_ptr<Entity>> entities;
};

