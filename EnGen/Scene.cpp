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
