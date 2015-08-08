#include "ResourceManager.h"

#if 0
const int Resources::tilesWidth = 13;
const int Resources::tilesHeight = 11;
const int Resources::tilesPadding = 1;
#endif 

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

sf::Sprite ResourceManager::GetSpriteByName(Resources::BlockSprites sprite)
{
	assert(sprite < Resources::NumAssignedSprites);
    sf::Sprite result;
    sf::IntRect texRect;

    u32 x = sprite / Resources::tilesWidth;
    x += (sprite % Resources::tilesWidth) * Resources::tilesPadding;

    u32 y = sprite % Resources::tilesWidth;
    y += sprite / Resources::tilesWidth;

    texRect.left = x;
    texRect.top = y;

    result.setPosition(0, 0);
    result.setTextureRect(texRect);
    result.setScale(metersPerPixel, metersPerPixel);
    return result;
}

sf::Sprite* ResourceManager::CreateSpriteByName(Resources::BlockSprites sprite)
{
	assert(sprite < Resources::NumAssignedSprites);
    // std::shared_ptr<sf::Sprite> result = std::make_shared<sf::Sprite>(new sf::Sprite);
    sf::Sprite* result = new sf::Sprite(*GetTexture(Resources::TILE_IMG));
    sf::IntRect texRect;

    u32 x = sprite / Resources::tilesWidth;
    x += (sprite % Resources::tilesWidth) * Resources::tilesPadding;

    u32 y = sprite % Resources::tilesWidth;
    y += sprite / Resources::tilesWidth * Resources::tilesPadding;

    texRect.left = x;
    texRect.top = y;
	texRect.width = Resources::tilesPixelSize;
	texRect.height = Resources::tilesPixelSize;

    result->setPosition(0, 0);
    result->setTextureRect(texRect);
    result->setScale(metersPerPixel, metersPerPixel);
    return result;
}
