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

	static ResourceManager* Get();
private:
	static ResourceManager* s_rm;

	sf::Texture textures[Resources::IMG_FILE_COUNT];
};

