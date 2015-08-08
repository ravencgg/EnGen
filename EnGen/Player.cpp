#include "Player.h"

#include "scene.h"

Player::Player(Scene* parent)
    : Entity(new sf::Sprite(*ResourceManager::Get()->GetTexture(Resources::ANIMATION_IMG)), parent)
{
	sprite->setPosition(0, 0);
	sprite->setTextureRect(sf::IntRect(21, 904, 26, 32));
	sprite->setScale(metersPerPixel, metersPerPixel);
    drawLayer = DrawLayer::PLAYER;

    entityTag = EntityTag::PLAYER;

    // Done in the entity constructor now.
	// parentScene = parent;

	sf::FloatRect fr = sprite->getLocalBounds();

	collisionRect = std::make_shared<sf::RectangleShape>();
	collisionRect->setFillColor(sf::Color(0, 0, 0, 0));
	collisionRect->setOutlineColor(sf::Color(50, 50, 150, 250));
	collisionRect->setOutlineThickness(0.1f);
	sf::Vector2f size(fr.width, fr.height);
	collisionRect->setSize(size * metersPerPixel);
}

Player::~Player()
{
}

void Player::Update(float dt)
{
    Input* input = Input::Get();
	float speed = 4.f;

	if (input->IsDown(sf::Keyboard::A))
	{
		velocity.x = -speed * dt;
	}
	else if (input->IsDown(sf::Keyboard::D))
	{
		velocity.x = speed * dt;
	}
	else
	{
		velocity.x = 0;
	}

	if (input->IsDown(sf::Keyboard::W))
	{
		velocity.y = speed * dt;
	}
	else if (input->IsDown(sf::Keyboard::S))
	{
		velocity.y = -speed * dt;
	}
	else
	{
		velocity.y = 0;
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
		sf::Vector2f pos(position.x, position.y);
		collisionRect->setPosition(pos);
		parentScene->AddDebugShape(collisionRect);
	}
}
