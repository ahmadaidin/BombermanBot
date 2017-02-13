#pragma once

#include "../../Header.h"
#include "../Entity.hpp"
#include "../Location.hpp"
class Player : public Entity {
public:
	Player() {
		Entity(PLAYER);
	}

	Player(Location location, string name, char key, int points, int bombBag, int bombRadius) {
		Entity(PLAYER,location);
		setName(name);
		setKey(key);
		setPoint(points);
		setBombag(bombBag);
		setBombRadius(bombRadius);
		setKilled(false);
	}

	Player operator= (Player &player) {
		Entity:setLocation(player.location);
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

	void setBombRadius(int bomRadius) {
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

	int move(int dx, int dy) {
	Entity:location.move(dx, dy);
	}

private:
	string name;
	char key;
	int points;
	bool killed;
	int bombBag;
	int bombRadius;

};