#pragma once
#include <SFML/Graphics.hpp>
#include "types.h"
#include <memory>


class Scene;

enum class TileType { Empty, Brick, Count };

struct Tile
{
	Tile() {}
	Tile(TileType t, std::shared_ptr<sf::Sprite> s)
		: type(t)
		, sprite(s)
	{}

    TileType type;
	std::shared_ptr<sf::Sprite> sprite;
};


class Tilemap
{
public:
    Tilemap(Scene*);
    ~Tilemap() {}

    void Create(u32, u32);
    void Render();
    
	void SetTile(u32, u32, TileType);
    void MakeRoom();

private:
    u32 m_width; 
    u32 m_height;

    Scene* parentScene;
    Array<Tile> tiles;
    bool m_displayBorders;

	sf::Sprite sprites[(u32)TileType::Count];
};
