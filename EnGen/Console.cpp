#include "Console.h"

Console* Console::sConsole = nullptr;

Console* Console::Get()
{
	if (!sConsole)
	{
		sConsole = new Console();
	}
	return sConsole;
}

Console::Console()
{
	std::string fontPath(res_path);
	// Pick a better one: https://www.google.com/fonts/
	fontPath.append("VT323-Regular.ttf");
	if (!font.loadFromFile(fontPath))
	{
		assert(!"Font failed to load!");
	}
	text.setFont(font);
}

Console::~Console()
{
}

void Console::RenderAndClearLog(sf::RenderWindow& outputWindow)
{
	sf::View oldView;
	oldView = outputWindow.getView();

	sf::View defaultView;
	outputWindow.setView(defaultView);

	float yLoc = 0;

	for (uint32 i = 0; i < messages.size(); ++i)
	{
		text.setPosition(0, yLoc);
		yLoc += text.getCharacterSize();
		text.setString(messages[i]);
		outputWindow.draw(text);
	}
	messages.clear();

	outputWindow.setView(oldView);
}

void Console::LogMessage(std::string message)
{
	messages.push_back(message);
}
