#pragma once
#ifndef Entity_HPP
#define Entity_HPP

#include "../Header.h"
#include "Location.hpp"

class Entity {
public:
	Entity() {
		this->location.setLocation(0, 0);
	}

	Entity(Location location) {
		this->location = location;
	}

	void setLocation(Location location) {
		this->location = location;
	}

	Location getLocation() {
		return this->location;
	}

	virtual string toString() {
		return " ";
	}
	
	int getPossiblePoints() {
		return 0;
	}

	virtual string getType() {
		return " ";
	}

private:
	Location location;
};

#endif
