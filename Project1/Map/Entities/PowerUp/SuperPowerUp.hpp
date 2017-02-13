#pragma once
#pragma once
#include "PowerUp.hpp"

class SuperPowerUp : public PowerUp {
public:
	SuperPowerUp() {
		PowerUp(BOMB_RAD_POW_UP);
	}

	SuperPowerUp(Location location) {
		PowerUp(BOMB_RAD_POW_UP, location);
	}

	SuperPowerUp operator= (SuperPowerUp &superPowerUp) {
	PowerUp:setLocation(superPowerUp.getLocation());
		return *this;
	}

	int getPossiblePoints() {
		return 100;
	}
};