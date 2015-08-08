#include "Level.h"

Level::Level()
	: Scene()
    , tilemap(this)
{
	Player* player = new Player(this);
	this->AddEntity((Entity*) player);

    this->AddEntity(new Enemy(this));
    this->AddEntity(new Enemy(this));

    tilemap.Create(32, 32);
    tilemap.MakeRoom();
}

Level::~Level()
{

}

std::vector < std::shared_ptr<sf::RectangleShape>> grid;
static bool init = false;

void Level::Update(float dt)
{
    for(uint32 i = 0; i < entities.size(); ++i)
    {
        entities[i]->Update(dt);
    }
    tilemap.Render();

	const int32 width = 32;
	const int32 height = 32;

	if (!init)
	{
		init = true;
		grid.reserve(width * height);
		for (int i = 0; i < width * height; ++i)
		{
			sf::RectangleShape* s = new sf::RectangleShape();
			grid.push_back(std::shared_ptr<sf::RectangleShape>(s));
		}
	}

	sf::Vector2f position(0, 0);
	for (int32 y = 0; y < height; ++y)
	{
		for (int32 x = 0; x < width; ++x)
		{
			int32 l = x + y * width;

			sf::Vector2f size(1, 1);
			grid[l]->setSize(size);
			grid[l]->setFillColor(sf::Color(0, 0, 0, 0));
			grid[l]->setOutlineColor(sf::Color(0, 255, 255, 180));
			grid[l]->setOutlineThickness(1.f * metersPerPixel);
			position.x = (float)x;
			position.y = (float)y;
			grid[l]->setPosition(position);

			this->AddDebugShape(grid[l]);
		}
	}
}

void Level::Render(sf::RenderWindow* window)
{

	for (uint32 i = 0; i < DrawLayer::LAYER_COUNT; ++i)
	{
		for (uint32 j = 0; j < sprites[i].size(); ++j)
		{
			//sf::RenderStates states;
			//states.blendMode = sf::BlendAlpha;
			//window->draw(*sprites[i][j], states);
			sf::Vector2f pos = sprites[i][j]->getPosition();
			pos.y = -pos.y;
			sprites[i][j]->setPosition(pos);
			window->draw(*sprites[i][j]);
			pos.y = -pos.y;
			sprites[i][j]->setPosition(pos);
		}
		sprites[i].clear();
	}

	// if draw debug shapes
	for (uint32 i = 0; i < debugShapes.size(); ++i)
	{
			sf::Vector2f pos = debugShapes[i]->getPosition();
			pos.y = -pos.y;
			debugShapes[i]->setPosition(pos);
			window->draw(*debugShapes[i]);
			pos.y = -pos.y;
			debugShapes[i]->setPosition(pos);
	}
	debugShapes.clear();
}
