#pragma once
#include "../../../Header.h"
#include "../../Entity.hpp"

class PowerUp :public Entity {
public :
	PowerUp() {
	}

	PowerUp(Location location) {
		setLocation(location);
	}

	~PowerUp() {

	}

};