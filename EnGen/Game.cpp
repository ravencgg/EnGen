#include "Game.h"


Game::Game()
{
	activeScene = new Level();
}

Game::~Game()
{
}

void Game::Update(float dt)
{
	if (activeScene)
	{
		activeScene->Update(dt);
	}
}

void Game::Render(sf::RenderWindow* window)
{
	if (activeScene)
	{
		activeScene->Render(window);
	}
}
