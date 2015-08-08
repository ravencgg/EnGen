#include "Enemy.h"

#include "scene.h"

Enemy::Enemy(Scene* parent)
    : Entity(new sf::Sprite(*ResourceManager::Get()->GetTexture(Resources::ANIMATION_IMG)), parent)
{
    sprite->setPosition(0, 0);
    sprite->setTextureRect(sf::IntRect(128, 1320, 34, 34));
    sprite->setScale(metersPerPixel, metersPerPixel);

    drawLayer = DrawLayer::PLAYER;

    entityTag = EntityTag::ENEMY;

    sf::FloatRect fr = sprite->getLocalBounds();

    collisionRect = std::make_shared<sf::RectangleShape>();
    collisionRect->setFillColor(sf::Color(0, 0, 0, 0));
    collisionRect->setOutlineColor(sf::Color(50, 50, 150, 250));
    collisionRect->setOutlineThickness(0.1f);
    sf::Vector2f size(fr.width, fr.height);
    collisionRect->setSize(size * metersPerPixel);

    int max_distance = 20;

    position.x = (float)(rand() % max_distance) - (float)(max_distance / 2);
    position.y = (float)(rand() % max_distance) - (float)(max_distance / 2);
}

Enemy::~Enemy()
{
}

void Enemy::Update(float dt) 
{

    player = parentScene->FindFirstEntityWithTag(EntityTag::PLAYER);

    float speed = 1.0f;

    if(auto p = player.lock())
    {
        Vec2 dir = p->position - position;

        float dirLen = sqrt(dir.x * dir.x + dir.y * dir.y);
        dir.x /= dirLen;
        dir.y /= dirLen;
        velocity = dir * speed * dt;
		
        position += velocity;
    }
    else
    {
        position.x += -1.f * dt;
    }

    std::string enemyPos("Enemy pos: ");
    enemyPos.append(std::to_string(position.x));
    enemyPos.append(" ");
    enemyPos.append(std::to_string(position.y));
    Console::Get()->LogMessage(enemyPos);

    sprite->setPosition(position.x, position.y);
    parentScene->AddDrawable(sprite, drawLayer);
}
