#pragma once
#include "types.h"
#include <vector>

class Tilemap
{
public:
	Tilemap();
	~Tilemap();


private:
	int32 width;
	int32 height;

	bool drawDebugGrid;
};

