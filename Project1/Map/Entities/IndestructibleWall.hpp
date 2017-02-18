#pragma once
#pragma once
#include "../../Header.h"
#include "../Entity.hpp"

class IndestructibleWall : public Entity {
public:

	IndestructibleWall() {
	
	}

	IndestructibleWall(Location location) {
		setLocation(location);
	}

	~IndestructibleWall() {

	}

	IndestructibleWall& operator = (const IndestructibleWall &wall) {
		return *this;
	}

	string toString() {
		return "{IndestructibleWall}(X:{" + to_string(getLocation().getAbsis()) + "}, Y:{" + to_string(getLocation().getOrdinat()) + "})";
	}
};