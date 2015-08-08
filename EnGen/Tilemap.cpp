#include "Tilemap.h"

#include "Scene.h"

Tilemap::Tilemap(Scene* s)
: parentScene(s)
{
}

void Tilemap::Create(u32 width, u32 height)
{
    this->m_width = width;
    this->m_height = height;

    tiles.Reserve(width * height);

    for(u32 y = 0; y < width; ++y)
    {
        for(u32 x = 0; x < width; ++x)
        {
			std::shared_ptr<sf::Sprite> s = std::make_shared<sf::Sprite>(*ResourceManager::Get()->CreateSpriteByName(Resources::Brick));
            tiles.Add(Tile(TileType::Empty, s));
        }
    }
}

void Tilemap::SetTile(u32 x, u32 y, TileType type)
{
    if(x > m_width || y > m_height) return;
    u32 index = x + y * m_width;
    tiles[index].type = type;
}

void Tilemap::MakeRoom()
{
    for(u32 y = 0; y < m_height; ++y)
    {
        for(u32 x = 0; x < m_width; ++x)
        {
            if(y == 0 || y == m_height - 1)
            {
                SetTile(x, y, TileType::Brick);
            }
            else if(x == 0 || x == m_width - 1)
            {
                SetTile(x, y, TileType::Brick);
            }
            else 
            {
                SetTile(x, y, TileType::Empty);
            }
        }
    }
}

void Tilemap::Render()
{
    for(u32 y = 0; y < m_width; ++y)
    {
        for(u32 x = 0; x < m_width; ++x)
        {
			u32 index = x + y * m_width;
			if (tiles[index].type != TileType::Empty)
			{
				tiles[index].sprite->setPosition((float)x, (float)y);
				parentScene->AddDrawable(std::shared_ptr<sf::Sprite>(tiles[index].sprite), DrawLayer::TILEMAP);
			}
        }
    }
}
