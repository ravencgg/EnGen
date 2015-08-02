#include "Player.h"

#include "scene.h"

Player::Player(Scene* parent)
	: sprite(new sf::Sprite(*ResourceManager::Get()->GetTexture(Resources::ANIMATION_IMG)))
{
	sprite->setPosition(0, 0);
	sprite->setTextureRect(sf::IntRect(17, 903, 34, 34));
    drawLayer = DrawLayer::PLAYER;
	parentScene = parent;
}

Player::~Player()
{
}

void Player::Update(float dt)
{
	static float time = 0;
	time += dt;

	//float scale = (sin(time) + 2) * 2;
	float scale = 2.f;
	sprite->setScale(scale, scale);
	sprite->setPosition((float)cos(time) * 200.f, (float)sin(time) * 200.f);
	//sprite->setPosition((float)cos(time / 2.f) * 400.f, 0);


	parentScene->AddDrawable(sprite, drawLayer);
}