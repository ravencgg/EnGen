#include "Entity.h"


Entity::Entity(sf::Sprite* s, Scene* parent)
: sprite(std::unique_ptr<sf::Sprite> (s))
, parentScene(parent)
{
}


Entity::~Entity()
{
}
