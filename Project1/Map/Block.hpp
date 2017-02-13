#pragma once

#include "../Header.h"
#include "Entity.hpp"
#include "Entities/Bomb.hpp"
#include "Entities/PowerUp/PowerUp.hpp"

class Block {
public:
	Block() {

	}

	Block(Location location, Entity entity, Bomb bomb, PowerUp powerUp) {
		this->location = location;
		this->entity = entity;
		this->bomb = bomb;
		this->powerUp = powerUp;
	}

	Block(Block &block) {
		this->location = block.location;
		this->entity = block.entity;
		this->bomb = block.bomb;
		this->powerUp = block.powerUp;
	}

	Block operator= (Block &block) {
		this->location = block.location;
		this->entity = block.entity;
		this->bomb = block.bomb;
		this->powerUp = block.powerUp;

		return *this;
	}

	void setLocation(Location location) {
		this->location = location;
	}

	void setEntity(Entity entity) {
		this->entity = entity;
	}

	void setBomb(Bomb bomb) {
		this->bomb = bomb;
	}

	void setPowerUp(PowerUp powerUp) {
		this->powerUp = powerUp;
	}

	Location getLocation() {
		return location;
	}

	Entity getEntity() {
		return entity;
	}

	Bomb getBomb() {
		return bomb;
	}

	PowerUp getPowerUp() {
		return powerUp;
	}

	
private:
	Location location;
	Entity entity;
	Bomb bomb;
	PowerUp powerUp;
};