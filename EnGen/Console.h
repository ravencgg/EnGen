#pragma once

#include <SFML/Graphics.hpp>

#include <assert.h>
#include <string>
#include <vector>
#include "types.h"
#include "ResourceManager.h"

class Console
{
public:
	Console();
	~Console();


	void LogMessage(char*);
	void LogMessage(std::string);
	void RenderAndClearLog(sf::RenderWindow&);

	static Console* Get();

private:
	static Console* sConsole;

	sf::Text text;
	sf::Font font;
	std::vector<std::string> messages;
};

