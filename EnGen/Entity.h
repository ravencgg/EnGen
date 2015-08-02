#pragma once

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void Update(float dt) = 0;
};

