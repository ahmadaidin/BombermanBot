#pragma once
#include "../../Header.h"
#include "../Entity.hpp"

class DestructibleWall : public Entity {
public:

	DestructibleWall() {
	
	}

	DestructibleWall(Location location) {
		setLocation(location);
	}

	~DestructibleWall() {

	}

	DestructibleWall& operator = (DestructibleWall &wall) {
		super:operator=(wall);
		return *this;
	}

	int getPossiblePoints() {
		return 30;
	}

	string toString() {
		return "{DestructibleWall}(X:{" + to_string(getLocation().getAbsis()) + "}, Y:{" + to_string(getLocation().getOrdinat()) + "})";
	}
};