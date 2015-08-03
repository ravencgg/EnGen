#include "ResourceManager.h"


ResourceManager* ResourceManager::s_rm = nullptr;

ResourceManager::ResourceManager()
{
	std::string tilePath = res_path + Files::tileFile;
	if (!textures[Resources::TILE_IMG].loadFromFile(tilePath))
	{
		assert(!"Broken!");
	}


	std::string animPath = res_path + Files::animFile;
	if (!textures[Resources::ANIMATION_IMG].loadFromFile(animPath))
	{
		assert(!"Broken!");
	}

	textures[Resources::TILE_IMG].setSmooth(true);
	textures[Resources::ANIMATION_IMG].setSmooth(true);
}

ResourceManager::~ResourceManager()
{
}

ResourceManager* ResourceManager::Get()
{
	if (!s_rm)
	{
		s_rm = new ResourceManager();
	}

	assert(s_rm);
	return s_rm;
}

sf::Texture* ResourceManager::GetTexture(Resources::TexFiles file)
{
	assert(file >= 0 && file < Resources::IMG_FILE_COUNT);
	return &textures[(uint32) file];
}
