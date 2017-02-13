#pragma once
#include "PowerUp.hpp"

class BombRadiusPowerUp : public PowerUp {
public:
	BombRadiusPowerUp() {
		PowerUp(BOMB_RAD_POW_UP);
	}

	BombRadiusPowerUp(Location location) {
		PowerUp(BOMB_RAD_POW_UP, location);
	}

	BombRadiusPowerUp  operator= (BombRadiusPowerUp &bombRadiusPowerUp) {
	PowerUp:setLocation(bombRadiusPowerUp.getLocation());
		return *this;
	}

	int getPossiblePoints() {
		return 50;
	}
};