#pragma once
#include "PowerUp.hpp"

class BombBagPowerUp: public PowerUp {
public :
	BombBagPowerUp() {
		PowerUp(BOMB_BAG_POW_UP);
	}

	BombBagPowerUp(Location location) {
		PowerUp(BOMB_BAG_POW_UP, location);
	}

	BombBagPowerUp operator= (BombBagPowerUp &bombBagPowerUp) {
		PowerUp:setLocation(bombBagPowerUp.getLocation());
		return *this;
	}

	int getPossiblePoints() {
		return 50;
	}
};