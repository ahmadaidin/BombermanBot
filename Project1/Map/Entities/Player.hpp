#pragma once

#include "../../Header.h"
#include "../Entity.hpp"

class Player : public Entity {
public:
	Player() {
		
	}

	Player(Location location, string name, char key, int points, int bombBag, int bombRadius) {
		setLocation(location);
		setName(name);
		setKey(key);
		setPoint(points);
		setBombag(bombBag);
		setBombRadius(bombRadius);
		setKilled(false);
	}

	Player& operator= (const Player &player) {
		super:operator= (player);
		setName(player.name);
		setKey(player.key);
		setPoint(player.points);
		setBombag(player.bombBag);
		setBombRadius(player.bombRadius);
		setKilled(player.killed);

		return *this;
	}

	int getPossiblePoint() {
		return 100;
	}

	~Player() {

	}

	void setName(string name) {
		this->name = name;
	}

	void setPoint(int points) {
		this->points = points;
	}

	void setKey(char key) {
		this->key = key;
	}

	void setKilled(bool killed) {
		this->killed = killed;
	}

	void setBombag(int bombBag) {
		this->bombBag = bombBag;
	}

	void setBombRadius(int bombRadius) {
		this->bombRadius = bombRadius;
	}

	string getName() {
		return name;
	}

	char getKey() {
		return key;
	}

	int getPoints() {
		return points;
	}

	int getBombBag() {
		return bombBag;
	}

	int getBombRadius() {
		return bombRadius;
	}

	int isKilled() {
		return killed;
	}
	

	string toString() {
		return "{Player}(X:{" + to_string(getLocation().getAbsis()) + "}, Y:{" + to_string(getLocation().getOrdinat()) + "}), Key:{" + getKey() + "})";
	}

private:
	string name;
	char key;
	int points;
	bool killed;
	int bombBag;
	int bombRadius;

};