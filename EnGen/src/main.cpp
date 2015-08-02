#include <Windows.h>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>

#include "../types.h"
#include "../Console.h"
#include "../Game.h"

typedef sf::Vector2f Vec2;

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
{
	int width  = 1100;
	int height = 800;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!", sf::Style::Default, settings);
	//window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	sf::View view(Vec2(0, 0), Vec2((float)width, (float)height));
	std::vector<std::unique_ptr<sf::Shape>> shapes;

	Game game;
	game.SetWindow(&window);

	for (int i = 0; i < 20; ++i)
	{
		shapes.push_back(std::make_unique<sf::CircleShape>(50.f));
		shapes.back()->setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
		shapes.back()->setPosition((float)(rand() % 1000), (float)(rand() % 200));
	}

	for (int i = 0; i < 20; ++i)
	{
		shapes.push_back(std::make_unique<sf::RectangleShape>());
		shapes.back()->setFillColor(sf::Color::Blue);
		shapes.back()->setPosition((float)(rand() % 20), (float)(rand() % 20));
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
				window.close();
		}

		   // Clock / FPS stuff
		static sf::Clock fpsClock;
		static uint32 frames = 0;
		static uint32 lastFPS = 0;
		if (fpsClock.getElapsedTime().asSeconds() < 1.0f)
		{
			++frames;
		}
		else
		{
			fpsClock.restart();
			lastFPS = frames;
			frames = 0;
		}
		std::string fpst("FPS: ");
		fpst.append(std::to_string(lastFPS));
		Console::Get()->LogMessage(fpst);
		static sf::Clock clock;
		sf::Time frameTime = clock.getElapsedTime();
		clock.restart();
		std::string ft("Frame time: ");
		ft.append(std::to_string(frameTime.asSeconds()));
		Console::Get()->LogMessage(ft);

		// Render stuff
		window.clear();
		window.setView(view);

		for (uint32 i = 0; i < shapes.size(); ++i)
		{
			//std::string m("There is a thing: ");
			//m.append(std::to_string(i));
			//Console::Get()->LogMessage(m);
			window.draw(*shapes[i].get());
		}
		game.Update(frameTime.asSeconds());
		game.Render(&window);
		Console::Get()->RenderAndClearLog(window);
		window.display();
	}

	return 0;
}