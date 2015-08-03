#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>

#include "Scene.h"
#include "types.h"
#include "Player.h"
#include "Console.h"
#include "Level.h"
#include "Input.h"


class Game
{
public:
	Game();
	~Game();

	void Run(sf::RenderWindow*);
	void Update(float dt);
	void Render(sf::RenderWindow*);

	void SetWindow(sf::RenderWindow* w) { drawWindow = w; }
	void SetScene(Scene* scene) { activeScene = scene; }

    // LoadLevel();
private:

	sf::RenderWindow* drawWindow = nullptr;
    Scene* activeScene = nullptr;
    // vector of inactive scenes?
};
