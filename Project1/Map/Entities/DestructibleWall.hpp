#pragma once
#include "../../Header.h"
#include "../Entity.hpp"

class DestructibleWall : public Entity {
public:

	DestructibleWall() {
		Entity(DES_WALL);
	}

	DestructibleWall(Location location) {
		Entity(DES_WALL,location);
	}

	~DestructibleWall() {

	}

	DestructibleWall operator = (DestructibleWall wall) {
		Entity:setLocation(wall.location);
		return *this;
	}

	int getPossiblePoints() {
		return 30;
	}
};