#pragma once

#include "types.h"

#if 0

struct Collider 
{
    Vec2 position;
    Vec2 size;
};

Array<Colliders> colliders;

struct PhysicsRect
{
    float x, y, w, h; 
};

//bool check_collision(PhysicsRect& m, Vec2& velocity, PhysicsRect& other, CollisionData& out);

// For detecting player/enemy or enemy/enemy collisions
// Does not return anything but the bool
bool intersects()
{
	return false;
}

class Physics
{
public:
	Physics();
	~Physics();
};
#endif
