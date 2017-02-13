#pragma once
#ifndef Entity_HPP
#define Entity_HPP

#include "../Header.h"
#include "Location.hpp"

class Entity {
public:
	Entity() {
		type = "";
		this->location = Location(0,0);
	}

	Entity(string type) {
		this->type =type;
		this->location = Location(0, 0);
	}

	Entity(string type, Location location) {
		this->type = type;
		this->location = location;
	}

	void setType(string type) {
		this->type = type;
	}

	string getType() {
		return type;
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
	string type;
};

#endif
