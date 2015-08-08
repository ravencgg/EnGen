#pragma once

#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "Tilemap.h"


enum TileLayers {TileLayers_Collideable, TileLayers_Count};

class Level : public Scene
{
public:
   	Level();
	virtual ~Level();

	virtual void Update(float) override;
	virtual void Render(sf::RenderWindow*) override;


private:
    Tilemap tilemap;
};

