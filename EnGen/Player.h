#pragma once
#include "Entity.h"

#include <memory>
#include <SFML/Graphics.hpp>
#include "types.h"
#include "ResourceManager.h"
#include "Input.h"
#include "Console.h"

class Scene;

class Player : public Entity
{
public:
	Player(Scene*);
	virtual ~Player();

	void Update(float) override;

private:
	Vec2 position;
	Vec2 velocity;

    std::shared_ptr<sf::RectangleShape> collisionRect;

	Scene* parentScene;
    DrawLayer::Enum drawLayer;
	std::shared_ptr<sf::Sprite> sprite;
};
