#pragma once
#include "Entity.h"

#include <memory>
#include <SFML/Graphics.hpp>
#include "types.h"
#include "ResourceManager.h"

class Scene;

class Player : public Entity
{
public:
	Player(Scene*);
	virtual ~Player();

	void Update(float) override;

private:
	Scene* parentScene;
    DrawLayer::Enum drawLayer;
	std::shared_ptr<sf::Sprite> sprite;
};
