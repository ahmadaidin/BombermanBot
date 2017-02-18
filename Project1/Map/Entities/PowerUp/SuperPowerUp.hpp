#pragma once
#pragma once
#include "PowerUp.hpp"

class SuperPowerUp : public PowerUp {
public:
	SuperPowerUp() {

	}

	SuperPowerUp(Location location) {
		setLocation(location);
	}

	SuperPowerUp operator= (SuperPowerUp &superPowerUp) {
	super:operator=(superPowerUp);
		return *this;
	}

	int getPossiblePoints() {
		return 100;
	}

	string toString() {
		return "{SuperPowerUp}(X:{" + to_string(getLocation().getAbsis()) + "}, Y:{" + to_string(getLocation().getOrdinat()) + "})";
	}
};