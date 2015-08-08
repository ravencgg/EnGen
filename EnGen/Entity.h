#pragma once

#include <SFML/Graphics.hpp>
#include "types.h"
#include "ResourceManager.h"
#include "Input.h"
#include "Console.h"
#include <memory>

class Scene;

enum class EntityTag : uint32 { UNKNOWN, PLAYER, ENEMY, TAG_COUNT };


class GameObject
{
public:
    GameObject() {}
    virtual ~GameObject() {}
};

class Entity //: public GameObject
{
public:
    Vec2 position;
    Vec2 velocity;
    EntityTag entityTag;

    Scene* parentScene;
    std::shared_ptr<sf::Sprite> sprite;
    DrawLayer::Enum drawLayer;
    std::shared_ptr<sf::RectangleShape> collisionRect;

	Entity(sf::Sprite*, Scene*);
	virtual ~Entity();

	virtual void Update(float dt) = 0;
};

