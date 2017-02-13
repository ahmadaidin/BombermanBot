#pragma once
#include "../../Header.h"
#include "Player.hpp"
#include "../Entity.hpp"

class Bomb:public Entity {
public:
	Bomb() {
		Entity(BOMB);
	}

	Bomb(Location location, Player owner, int timer, bool isExploding, int Points) {
		Entity(BOMB, location);
		setOwner(owner);
		setTimer(timer);
		setExploding(isExploding);
		setPoints(points);
	}

	Bomb operator= (Bomb &bomb) {
		Entity:setLocation(bomb.getLocation());
		setOwner(bomb.owner);
		setTimer(bomb.timer);
		setExploding(bomb.isExploding);
		setPoints(bomb.points);

		return *this;
	}

	~Bomb() {

	}

	void setOwner(Player owner) {
		this->owner = owner;
	}

	void setTimer(int timer) {
		this->timer = timer;
	}

	void setExploding(bool isExploding) {
		this->isExploding = isExploding;
	}

	void setPoints(int points) {
		this->points = points;
	}

private:
	Player owner;
	int timer;
	bool isExploding;
	int points;
};