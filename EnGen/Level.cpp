#include "Level.h"

Level::Level()
	: Scene()
{
	Player* player = new Player(this);
	this->AddEntity((Entity*) player);
}

Level::~Level()
{
}

void Level::Update(float dt)
{
    for(uint32 i = 0; i < entities.size(); ++i)
    {
        entities[i]->Update(dt);
    }
}

void Level::Render(sf::RenderWindow* window)
{
	for (uint32 i = 0; i < DrawLayer::LAYER_COUNT; ++i)
	{
		for (uint32 j = 0; j < sprites[i].size(); ++j)
		{
			window->draw(*sprites[i][j]);
		}
		sprites[i].clear();
	}
}
