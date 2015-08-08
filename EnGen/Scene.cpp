#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::AddEntity(Entity* e)
{
	std::unique_ptr<Entity> te(e);
	entities.push_back(std::move(te));
}

void Scene::AddDrawable(std::shared_ptr<sf::Sprite> sprite, DrawLayer::Enum dl)
{
	sprites[dl].push_back(sprite);
}

std::weak_ptr<Entity> Scene::FindFirstEntityWithTag(EntityTag tag)
{
    std::weak_ptr<Entity> result;

    for(uint32 i = 0; i < entities.size(); ++i)
    {
        if(entities[i]->entityTag == tag)
        {
            result = entities[i];
        }
    }

    return result;
}


void Scene::AddDebugShape(std::shared_ptr<sf::Shape> shape)
{
	debugShapes.push_back(shape);
}
