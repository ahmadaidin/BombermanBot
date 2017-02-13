#pragma once
#ifndef Entity_HPP
#define Entity_HPP

#include "Header.h"
#include "Location.hpp"

class Entity {
public:
	Entity() {
		this->location = Location(0,0);
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

	virtual int getPossiblePoint();

protected:
	Location location;

};

#endif
