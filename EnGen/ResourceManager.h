#pragma once

#include <SFML\Graphics.hpp>
#include "types.h"
#include <vector>
#include <memory>
#include <string>
#include <assert.h>

#ifdef _DEBUG
const std::string res_path("./../Release/res/");
#elif _NDEBUG
const std::string res_path("./res/");
#endif


namespace Resources
{
	enum TexFiles { TILE_IMG, ANIMATION_IMG, IMG_FILE_COUNT };

    enum BlockSprites { Stone = 0, HillTop, PlantLeft, PlantMiddle, PlantRight, Brick, MetalBlock, Axe,
                        Chain, Fence, SilverPole, SilverTubeTL, SilverTubeTR, HillLeft, HillMiddle, HillRight, 
                        HillBlank, HillMiddleR, CastleBlock, NumAssignedSprites};

    const int tilesWidth = 13;
    const int tilesHeight = 11;
    const int tilesPadding = 1;
	const int tilesPixelSize = 16;
}

namespace Files
{
	const std::string tileFile("tiles.png");
	const std::string animFile("anim.png");
}

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	sf::Texture* GetTexture(Resources::TexFiles);
    sf::Sprite GetSpriteByName(Resources::BlockSprites sprite);
    sf::Sprite* CreateSpriteByName(Resources::BlockSprites sprite);

	static ResourceManager* Get();
private:
	static ResourceManager* s_rm;

	sf::Texture textures[Resources::IMG_FILE_COUNT];
};

