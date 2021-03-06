#pragma once

#include "../Header.h"
#include "Entity.hpp"
#include "Entities/Bomb.hpp"
#include "Entities/PowerUp/PowerUp.hpp"

class Block {
public:
	Block() {

	}

	Block(Location location) {
		this->location = location;
	}

	Block(Location location, Entity *entity, Bomb *bomb, PowerUp *powerUp, bool exploading) {
		this->location = location;
		this->entity = entity;
		this->bomb = bomb;
		this->powerUp = powerUp;
		this->exploding = exploding;
	}

	Block(const Block &block) {
		this->location = block.location;
		this->entity = block.entity;
		this->bomb = block.bomb;
		this->powerUp = block.powerUp;
		this->exploding = block.exploding;
	}

	Block& operator= (Block &block) {
		this->location = block.location;
		this->entity = block.entity;
		this->bomb = block.bomb;
		this->powerUp = block.powerUp;
		this->exploding = block.exploding;

		return *this;
	}

	void setLocation(Location location) {
		this->location = location;
	}

	void setEntity(Entity *entity) {
		this->entity = entity;
	}

	void setBomb(Bomb *bomb) {
		this->bomb = bomb;
	}

	void setPowerUp(PowerUp *powerUp) {
		this->powerUp = powerUp;
	}

	void setExploding(bool exploding) {
		this->exploding = exploding;
	}

	Location getLocation() {
		return location;
	}

	Entity getEntity() {
		return *entity;
	}

	Bomb getBomb() {
		return *bomb;
	}

	PowerUp getPowerUp() {
		return *powerUp;
	}

	bool isExploding() {
		return exploding;
	}

	bool isNullEntity() {
		return (entity == NULL);
	}

	bool isNullBomb() {
		return (bomb == NULL);
	}

	bool isNullPowerUp() {
		return (powerUp == NULL);
	}


private:
	Location location;
	Entity *entity;
	Bomb *bomb;
	PowerUp *powerUp;
	bool exploding;
};
