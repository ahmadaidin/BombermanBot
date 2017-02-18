#pragma once

#include "../Header.h"
#include "../Map/Location.hpp"
#include "../Map/Entity.hpp"
#include "../Map/Block.hpp"

class Node {
public:
	Node() {

	}

	Node(Block block) {
		this->location = block.getLocation();
		*this->entity = block.getEntity();
		this->exploading = block.isExploding();
		*this->bomb = block.getBomb();
	}

	Node(Location location, Bomb *bomb, Entity *entity, bool exploading) {
		setLocation(location);
		setBomb(bomb);
		setEntity(entity);
		setExploading(exploading);
	}

	Node(Location location, Bomb *bomb, Entity *entity, bool exploading, vector<Node> neighbors) {
		setLocation(location);
		setBomb(bomb);
		setEntity(entity);
		setExploading(exploading);
		setNeighbors(neighbors);
	}

	Node(Node &node) {
		setLocation(node.location);
		setBomb(node.bomb);
		setEntity(node.entity);
		setExploading(node.exploading);
		setNeighbors(node.neighbors);
	}

	Node operator= (Node &node) {
		setLocation(node.location);
		setBomb(node.bomb);
		setEntity(node.entity);
		setExploading(node.exploading);
		setNeighbors(node.neighbors);
		
		return *this;
	}

	void setLocation(Location location) {
		this->location = location;
	}

	void setBomb(Bomb *bomb) {
		this->bomb = bomb;
	}

	void setEntity(Entity *entity) {
		this->entity = entity;
	}

	void setExploading(bool exploading) {
		this->exploading = exploading;
	}

	void setNeighbors(vector<Node> neighbors) {
		this->neighbors = neighbors;
	}

	void addNeigbors(Node node) {
		neighbors.push_back(node);
	}

	Location getLocation() {
		return location;
	}

	Bomb getBomb() {
		return *bomb;
	}

	Entity getEntity() {
		return *entity;
	}

	bool isExploading() {
		return exploading;
	}

	vector<Node> getNeighbors() {
		return neighbors;
	}

	int getPoints() {
		return (entity == NULL ? 0 : entity->getPossiblePoint());
	}

	bool isBombPresent() {
		return bomb != NULL;
	}

private:
	Location location;
	Entity *entity;
	Bomb *bomb;
	bool exploading;
	vector<Node> neighbors;
};

