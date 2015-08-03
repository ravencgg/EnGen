#pragma once

#include "SFML/Graphics.hpp"
#include "types.h"
#include <string> // memset
#define NUM_KEYS 256

//enum class MouseButton { LEFT, MIDDLE, RIGHT, COUNT };
enum class KeyState { UP, FRAME_UP, DOWN, FRAME_DOWN, DOWN_UP, UP_DOWN };

struct Mouse
{
	Point2 p;
	Point2 delta;
	KeyState buttons[sf::Mouse::ButtonCount];
};

class Input
{
public:

	Input();
	~Input() {};
	static Input* Get();

	void BeginFrame();

	// Keyboard handling
	void ProcessKeyPress(int32 key);
	void ProcessKeyRelease(int32 key);

	bool OnUp(sf::Keyboard::Key key);
	bool OnDown(sf::Keyboard::Key key);
	bool IsDown(sf::Keyboard::Key key);
	bool IsUp(sf::Keyboard::Key key);

	// Mouse handling
	void MouseMoveEvent(sf::Event::MouseMoveEvent&);
	void MouseButtonPressed(sf::Event::MouseButtonEvent&);
	void MouseButtonReleased(sf::Event::MouseButtonEvent&);

	Point2 MouseLoc();
	Point2 MouseDelta();

	bool OnDown(sf::Mouse::Button);
	bool OnUp(sf::Mouse::Button);
	bool IsDown(sf::Mouse::Button);
	bool IsUp(sf::Mouse::Button);

private:

	static Input* s_input;

	void UpdateKeys();
	void UpdateMouse();

	KeyState key_states[NUM_KEYS];
	Mouse mouse;
	bool mouse_loc_updated_this_frame = false;
}; 
