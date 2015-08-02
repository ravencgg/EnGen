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


class Game
{
public:
	Game();
	~Game();

	void Update(float dt);
	void Render(sf::RenderWindow*);

	void SetWindow(sf::Window* w) { drawWindow = w; }
	void SetScene(Scene* scene) { activeScene = scene; }

    // LoadLevel();
private:

	sf::Window* drawWindow = nullptr;
    Scene* activeScene = nullptr;
    // vector of inactive scenes?
};
