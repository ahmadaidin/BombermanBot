#pragma once
#include "PowerUp.hpp"

class BombRadiusPowerUp : public PowerUp {
public:
	BombRadiusPowerUp() {
	}

	BombRadiusPowerUp(Location location) {
		setLocation(location);
	}

	BombRadiusPowerUp&  operator= (const BombRadiusPowerUp &bombRadiusPowerUp) {

		return *this;
	}

	int getPossiblePoints() {
		return 50;
	}

	string toString() {
		return "{BombRadiusPowerUp}(X:{" + to_string(getLocation().getAbsis()) + "}, Y:{" + to_string(getLocation().getOrdinat()) + "})";

	}
};