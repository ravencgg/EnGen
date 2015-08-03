#include "Input.h"

Input* Input::s_input = nullptr;

Input::Input()
{
	memset(&key_states[0], 0, NUM_KEYS * sizeof(key_states[0]));
	mouse = {};
}

Input* Input::Get()
{
	if (!s_input)
	{
		s_input = new Input();
	}
	return s_input;
}

void Input::BeginFrame()
{
	mouse_loc_updated_this_frame = false;

	UpdateKeys();
	UpdateMouse();
}

void Input::UpdateKeys()
{
	for (int i = 0; i < NUM_KEYS; ++i)
	{
		if (key_states[i] == KeyState::FRAME_UP || key_states[i] == KeyState::DOWN_UP)
		{
			key_states[i] = KeyState::UP;
		}
		else if (key_states[i] == KeyState::FRAME_DOWN || key_states[i] == KeyState::UP_DOWN)
		{
			key_states[i] = KeyState::DOWN;
		}
	}
}

void Input::ProcessKeyPress(int32 key)
{
	if (key_states[key] == KeyState::FRAME_UP)
		key_states[key] = KeyState::UP_DOWN;

	else if (key_states[key] == KeyState::DOWN_UP)
		key_states[key] = KeyState::UP_DOWN;

	else if (key_states[key] != KeyState::DOWN)
		key_states[key] = KeyState::FRAME_DOWN;
}

void Input::ProcessKeyRelease(int32 key)
{
	if (key_states[key] == KeyState::FRAME_DOWN)
		key_states[key] = KeyState::DOWN_UP;

	else if (key_states[key] == KeyState::UP_DOWN)
		key_states[key] = KeyState::DOWN_UP;

	else if (key_states[key] != KeyState::UP)
		key_states[key] = KeyState::FRAME_UP;
}

bool Input::OnDown(sf::Keyboard::Key key)
{
	bool result = (key_states[key] == KeyState::FRAME_DOWN
		|| key_states[key] == KeyState::DOWN_UP
		|| key_states[key] == KeyState::UP_DOWN);

	return result;
}

bool Input::OnUp(sf::Keyboard::Key key)
{
	bool result = (key_states[key] == KeyState::FRAME_UP
		|| key_states[key] == KeyState::DOWN_UP
		|| key_states[key] == KeyState::UP_DOWN);

	return result;
}

bool Input::IsDown(sf::Keyboard::Key key)
{
	bool result = (key_states[key] == KeyState::FRAME_DOWN
		|| key_states[key] == KeyState::DOWN
		|| key_states[key] == KeyState::UP_DOWN
		|| key_states[key] == KeyState::DOWN_UP);

	return result;
}

bool Input::IsUp(sf::Keyboard::Key key)
{
	bool result = (key_states[key] == KeyState::FRAME_UP
		|| key_states[key] == KeyState::UP
		|| key_states[key] == KeyState::DOWN_UP
		|| key_states[key] == KeyState::UP_DOWN);

	return result;
}

void Input::UpdateMouse()
{
	for (int32 i = 0; i < sf::Mouse::ButtonCount; ++i)
	{
		if (mouse.buttons[i] == KeyState::FRAME_UP)
		{
			mouse.buttons[i] = KeyState::UP;
		}
		else if (mouse.buttons[i] == KeyState::FRAME_DOWN)
		{
			mouse.buttons[i] = KeyState::DOWN;
		}
	}

	//if (mouse.buttons[(int32)MouseButton::MIDDLE] == KeyState::FRAME_UP) mouse.buttons[(int32)MouseButton::MIDDLE] = KeyState::UP;
	//else if (mouse.buttons[(int32)MouseButton::MIDDLE] == KeyState::FRAME_DOWN) mouse.buttons[(int32)MouseButton::MIDDLE] = KeyState::DOWN;

	//if (mouse.buttons[(int32)MouseButton::RIGHT] == KeyState::FRAME_UP) mouse.buttons[(int32)MouseButton::RIGHT] = KeyState::UP;
	//else if (mouse.buttons[(int32)MouseButton::RIGHT] == KeyState::FRAME_DOWN) mouse.buttons[(int32)MouseButton::RIGHT] = KeyState::DOWN;
}

void Input::MouseMoveEvent(sf::Event::MouseMoveEvent& event)
{
	Point2 new_position;
	new_position.x = event.x;
	new_position.y = event.y;

	if (!mouse_loc_updated_this_frame)
	{
		mouse_loc_updated_this_frame = true;
		mouse.delta.x = 0;
		mouse.delta.y = 0;
	}

	mouse.delta.x += new_position.x - mouse.p.x;
	mouse.delta.y += new_position.y - mouse.p.y;
	mouse.p = new_position;
}

void Input::MouseButtonPressed(sf::Event::MouseButtonEvent& event)
{
	int32 m = event.button;
	if (mouse.buttons[event.button] != KeyState::DOWN)
	{
		mouse.buttons[event.button] = KeyState::FRAME_DOWN;
	}
}

void Input::MouseButtonReleased(sf::Event::MouseButtonEvent& event)
{
	if (mouse.buttons[event.button] != KeyState::UP)
	{
		mouse.buttons[event.button] = KeyState::FRAME_UP;
	}

	//if (m & SDL_BUTTON(SDL_BUTTON_MIDDLE)) // Button down happened
	//{
	//	if (mouse.buttons[(int32)MouseButton::MIDDLE] != KeyState::DOWN)
	//	{
	//		mouse.buttons[(int32)MouseButton::MIDDLE] = KeyState::FRAME_DOWN;
	//	}
	//}
	//else // Button up happened
	//{
	//	if (mouse.buttons[(int32)MouseButton::MIDDLE] != KeyState::UP)
	//	{
	//		mouse.buttons[(int32)MouseButton::MIDDLE] = KeyState::FRAME_UP;
	//	}
	//}

	//if (m & SDL_BUTTON(SDL_BUTTON_RIGHT)) // Button down happened
	//{
	//	if (mouse.buttons[(int32)MouseButton::RIGHT] != KeyState::DOWN)
	//	{
	//		mouse.buttons[(int32)MouseButton::RIGHT] = KeyState::FRAME_DOWN;
	//	}
	//}
	//else // Button up happened
	//{
	//	if (mouse.buttons[(int32)MouseButton::RIGHT] != KeyState::UP)
	//	{
	//		mouse.buttons[(int32)MouseButton::RIGHT] = KeyState::FRAME_UP;
	//	}
	//}
}

Point2 Input::MouseLoc()
{
	return mouse.p;
}

Point2 Input::MouseDelta()
{
	return mouse.delta;
}

bool Input::OnDown(sf::Mouse::Button button)
{
	bool result = (mouse.buttons[button] == KeyState::FRAME_DOWN);
	return result;
}

bool Input::OnUp(sf::Mouse::Button button)
{
	bool result = mouse.buttons[button] == KeyState::FRAME_UP;
	return result;
}

bool Input::IsDown(sf::Mouse::Button button)
{
	bool result = (mouse.buttons[button] == KeyState::FRAME_DOWN || mouse.buttons[button] == KeyState::DOWN);
	return result;
}

bool Input::IsUp(sf::Mouse::Button button)
{
	bool result = (mouse.buttons[button] == KeyState::FRAME_UP || mouse.buttons[button] == KeyState::UP);
	return result;
}
