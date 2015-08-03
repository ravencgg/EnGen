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

std::vector < std::shared_ptr<sf::RectangleShape>> grid;
static bool init = false;

void Level::Update(float dt)
{
    for(uint32 i = 0; i < entities.size(); ++i)
    {
        entities[i]->Update(dt);
    }

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

	Vec2 position(0, 0);
	for (int32 y = 0; y < height; ++y)
	{
		for (int32 x = 0; x < width; ++x)
		{
			int32 l = x + y * width;
			grid[l]->setSize(Vec2(30.f, 30.f));
			grid[l]->setFillColor(sf::Color(0, 0, 0, 0));
			grid[l]->setOutlineColor(sf::Color(0, 255, 255, 180));
			grid[l]->setOutlineThickness(4.f);
			position.x = (float)x * 30.f;
			position.y = (float)y * 30.f;
			grid[l]->setPosition(position);

			this->AddDebugShape(grid[l]);

			//shape->setSize(Vec2(30.f, 30.f));
			//shape->setFillColor(sf::Color(0, 0, 0, 0));
			//shape->setOutlineColor(sf::Color(0, 255, 255, 180));
			//shape->setOutlineThickness(4.f);
			//position.x = (float)x * 30.f;
			//position.y = (float)y * 30.f;
			//shape->setPosition(position);

			//this->AddDebugShape(std::shared_ptr<sf::Shape> (&grid[l]));
			//this->AddDebugShape(std::);
			//window->draw(grid[l]);
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
			Vec2 pos = sprites[i][j]->getPosition();
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
			Vec2 pos = debugShapes[i]->getPosition();
			pos.y = -pos.y;
			debugShapes[i]->setPosition(pos);
			window->draw(*debugShapes[i]);
			pos.y = -pos.y;
			debugShapes[i]->setPosition(pos);
	}
	debugShapes.clear();
}
