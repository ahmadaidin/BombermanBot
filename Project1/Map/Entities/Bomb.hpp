#pragma once
#include "../../Header.h"
#include "Player.hpp"
#include "../Entity.hpp"

class Bomb:public Entity {
public:
	Bomb() {
	}

	Bomb(Location location, Player owner, int timer, int radius, bool isExploding, int Points) {
		setLocation(location);
		setOwner(owner);
		setTimer(timer);
		setRadius(radius);
		setExploding(isExploding);
		setPoints(Points);
	}

	Bomb& operator= (Bomb &bomb) {
		super:operator=(bomb);
		setOwner(bomb.owner);
		setTimer(bomb.timer);
		setRadius(bomb.radius);
		setExploding(bomb.isExploading);
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

	void setRadius(int radius) {
		this->radius = radius;
	}

	void setExploding(bool isExploding) {
		this->isExploading = isExploding;
	}

	void setPoints(int points) {
		this->points = points;
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
		return isExploading;
	}

	int getPoints() {
		return points;
	}


	string toString() {
		return "{Bomb}(X:{"+std::to_string(getLocation().getAbsis())+"}, Y : {"+ to_string(getLocation().getOrdinat())+"}), Raduis : {"+ to_string(getRadius())+"}, Timer : {"+to_string(getTimer())+"}, Owner : {"+getOwner().getKey()+"}";
	}

private:
	Player owner;
	int timer;
	int radius;
	bool isExploading;
	int points;
};