#pragma once
#pragma once
#include "../../Header.h"
#include "../Entity.hpp"

class IndestructibleWall : public Entity {
public:

	IndestructibleWall() {
		Entity(INDES_WALL);
	}

	IndestructibleWall(Location location) {
		Entity(INDES_WALL,location);
	}

	~IndestructibleWall() {

	}

	IndestructibleWall operator = (IndestructibleWall wall) {
	Entity:setLocation(wall.location);
		return *this;
	}
};