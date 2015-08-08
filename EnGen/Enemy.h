#pragma once
#include "Entity.h"

#include <memory>
#include <SFML/Graphics.hpp>
#include "types.h"
#include "ResourceManager.h"
#include "Input.h"
#include "Console.h"

class Scene;

class Enemy : public Entity
{
public:
	Enemy(Scene*);
	virtual ~Enemy();


    void Update(float) override;

private:
    std::weak_ptr<Entity> player;
};
