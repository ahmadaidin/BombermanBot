#pragma once
#include "../../Header.h"
#include "Player.hpp"
#include "../Entity.hpp"

class Bomb:public Entity {
public:
	Bomb() {
	}

	Bomb(Location location, Player owner, int timer, int radius, bool isExploding) {
		setLocation(location);
		setOwner(owner);
		setTimer(timer);
		setRadius(radius);
		setExploding(isExploding);
	}

	Bomb(Bomb const &bomb) {
		setOwner(bomb.owner);
		setTimer(bomb.timer);
		setRadius(bomb.radius);
		setExploding(bomb.isExploding);
	}

	Bomb& operator= (const Bomb &bomb) {
		//super:operator=(bomb);
		setOwner(bomb.owner);
		setTimer(bomb.timer);
		setRadius(bomb.radius);
		setExploding(bomb.isExploding);

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

	void setRadius(int radius) {
		this->radius = radius;
	}

	void setExploding(bool isExploding) {
		this->isExploding = isExploding;
	}

	Player getOwner() {
		return owner;
	}

	int getTimer() {
		return timer;
	}

	int getRadius() {
		return radius;
	}

	bool getExploading() {
		return isExploding;
	}

	string toString() {
		return "{Bomb}(X:{"+std::to_string(getLocation().getAbsis())+"}, Y : {"+ to_string(getLocation().getOrdinat())+"}), Raduis : {"+ to_string(getRadius())+"}, Timer : {"+to_string(getTimer())+"}, Owner : {"+getOwner().getKey()+"}";
	}

private:
	Player owner;
	int timer;
	int radius;
	bool isExploding;
};