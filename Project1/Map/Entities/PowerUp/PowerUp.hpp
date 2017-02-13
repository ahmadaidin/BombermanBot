#pragma once

#include "../../Entity.hpp"

class PowerUp :public Entity {
public :
	PowerUp() {
		Entity(POWER_UP);
	}

	PowerUp(string powerType) {
		Entity(POWER_UP);
		this->powerType = powerType;
	}

	PowerUp(string powerType, Location location) {
		Entity(POWER_UP, location);
		this->powerType = powerType;
	}

	~PowerUp() {

	}

	void setPowerType(string powerType) {
		this->powerType = powerType;
	}

	string getPowerType() {
		return powerType;
	}

private:
	string powerType;
};