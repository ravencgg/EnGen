#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	std::vector<std::unique_ptr<sf::Shape>> shapes;

	for (int i = 0; i < 20; ++i)
	{
		shapes.push_back(std::make_unique<sf::CircleShape>());
		shapes.back()->setFillColor(sf::Color::Magenta);
		//shapes.back()->setPosition((float)(rand() % 20), (float)(rand() % 20));
		shapes.back()->setPosition(1.f, 1.f);
	}

	for (int i = 0; i < 20; ++i)
	{
		shapes.push_back(std::make_unique<sf::RectangleShape>());
		shapes.back()->setFillColor(sf::Color::Blue);
		shapes.back()->setPosition((float)(rand() % 20), (float)(rand() % 20));
	}

	sf::Vector2f pos(1.f, 1.f);
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


		window.clear();
		for (auto it = shapes.begin(); it != shapes.end(); ++it)
		{
			window.draw(*it->get());
		}
		window.display();
	}

	return 0;
}