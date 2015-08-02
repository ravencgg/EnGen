#pragma once

#include "Scene.h"
#include "Player.h"


class Level : public Scene
{
public:
	Level();
	virtual ~Level();

	virtual void Update(float) override;
	virtual void Render(sf::RenderWindow*) override;
};

