#pragma once
#include "PowerUp.hpp"

class BombBagPowerUp: public PowerUp {
public :
	BombBagPowerUp() {
		
	}

	BombBagPowerUp(Location location) {
		setLocation(location);
	}

	BombBagPowerUp& operator= (BombBagPowerUp &bombBagPowerUp) {
		super:operator=(bombBagPowerUp);
		return *this;
	}

	int getPossiblePoints() {
		return 50;
	}

	string toString() {
		return "{BombBagPowerUp}(X:{" + to_string(getLocation().getAbsis()) + "}, Y:{" + to_string(getLocation().getOrdinat()) + "})";
	}
};