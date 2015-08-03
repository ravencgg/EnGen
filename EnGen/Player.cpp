#include "Player.h"

#include "scene.h"

Player::Player(Scene* parent)
	: sprite(new sf::Sprite(*ResourceManager::Get()->GetTexture(Resources::ANIMATION_IMG)))
{
	sprite->setPosition(0, 0);
	sprite->setTextureRect(sf::IntRect(21, 904, 26, 32));
	sprite->setScale(metersPerPixel, metersPerPixel);
    drawLayer = DrawLayer::PLAYER;
	parentScene = parent;

	sf::FloatRect fr = sprite->getLocalBounds();

	collisionRect = std::make_shared<sf::RectangleShape>();
	collisionRect->setFillColor(sf::Color(0, 0, 0, 0));
	collisionRect->setOutlineColor(sf::Color(50, 50, 150, 250));
	collisionRect->setOutlineThickness(0.1f);
	Vec2 size(fr.width, fr.height);
	collisionRect->setSize(size * metersPerPixel);
}

Player::~Player()
{
}

void Player::Update(float dt)
{
	static float time = 0;
	time += dt;

	Vec2 velocity(0, 0);
	float speed = 4.f;

	Input* input = Input::Get();

	if (input->IsDown(sf::Keyboard::A))
	{
		velocity.x = -speed * dt;
	}
	if (input->IsDown(sf::Keyboard::D))
	{
		velocity.x = speed * dt;
	}
	if (input->IsDown(sf::Keyboard::W))
	{
		velocity.y = speed * dt;
	}
	if (input->IsDown(sf::Keyboard::S))
	{
		velocity.y = -speed * dt;
	}

	std::string playerPos("Player pos: ");
	playerPos.append(std::to_string(position.x));
	playerPos.append(" ");
	playerPos.append(std::to_string(position.y));
	Console::Get()->LogMessage(playerPos);

	this->position += velocity;
	sprite->setPosition(position.x, position.y);
	parentScene->AddDrawable(sprite, drawLayer);

	static bool draw = true;

	if (Input::Get()->OnDown(sf::Keyboard::M))
	{
		draw = !draw;
	}

	if (draw)
	{
		collisionRect->setPosition(this->position);
		parentScene->AddDebugShape(collisionRect);
	}
}
