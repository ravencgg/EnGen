#include "Game.h"

Game::Game()
{
	// Change to level loading stuff
	activeScene = new Level();
}

Game::~Game()
{
}

void Game::Run(sf::RenderWindow* window)
{
	sf::Vector2u screenSize = window->getSize();

	sf::View view(Vec2(0, 0), Vec2((float)screenSize.x, (float)screenSize.y));
	//sf::View view(Vec2(0, 0), Vec2(16.f, 9.f));
	std::vector<std::unique_ptr<sf::Shape>> shapes;

	Input* input = Input::Get();

	this->SetWindow(window);

	while (window->isOpen())
	{
		input->BeginFrame();
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
			if (event.type == sf::Event::Resized)
			{
				sf::Vector2u s = window->getSize();
				sf::Vector2f sf((float)s.x, (float)s.y);
				view.setSize(sf);
			}

		// Input processing
			if (event.type == sf::Event::KeyPressed)
			{
				input->ProcessKeyPress(event.key.code);
			}
			if (event.type == sf::Event::KeyReleased)
			{
				input->ProcessKeyRelease(event.key.code);
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				input->MouseButtonPressed(event.mouseButton);
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				input->MouseButtonReleased(event.mouseButton);
			}
			if (event.type == sf::Event::MouseMoved)
			{
				input->MouseMoveEvent(event.mouseMove);
			}
		// End input processing
		}

		if (input->IsDown(sf::Keyboard::Escape))
		{
			// TODO(cgenova): Clean way of breaking out of the loop?
			window->close();
			//break;
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
		// End Clock / FPS stuff


		if (input->IsDown(sf::Keyboard::Up))
		{
			view.zoom(1.1f);
		}
		if (input->IsDown(sf::Keyboard::Down))
		{
			view.zoom(0.9f);
		}

		// Render stuff
		window->clear();
		window->setView(view);

		std::string mouseStatus("Mouse location: ");
		mouseStatus.append(std::to_string(input->MouseLoc().x));
		mouseStatus.append(", ");
		mouseStatus.append(std::to_string(input->MouseLoc().y));
		Console::Get()->LogMessage(mouseStatus);

		std::string mouseButtons("Mouse Buttons: ");

		for (int32 i = 0; i < sf::Mouse::ButtonCount; ++i)
		{
			sf::Mouse::Button b = (sf::Mouse::Button) i;
			if (input->IsDown(b))
			{
				mouseButtons.append(std::to_string(i));
				mouseButtons.append(" ");
			}
		}
		Console::Get()->LogMessage(mouseButtons);

		for (uint32 i = 0; i < shapes.size(); ++i)
		{
			window->draw(*shapes[i].get());
		}
		this->Update(frameTime.asSeconds());
		this->Render(window);
		Console::Get()->RenderAndClearLog(*window);
		window->display();
	}
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
