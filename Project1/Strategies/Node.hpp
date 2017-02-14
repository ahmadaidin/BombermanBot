#pragma once

#include "../Header.h"
#include "../Map/Location.hpp"
#include "../Map/Entity.hpp"

class Node {
	Node() {

	}

	Node(Location location, Entity entity, bool exploading) {
		setLocation(location);
		setEntity(entity);
		setExploading(exploading);
	}

	Node(Location location, Entity entity, bool exploading, vector<Node> neighbors) {
		setLocation(location);
		setEntity(entity);
		setExploading(exploading);
		setNeighbors(neighbors);
	}

	Node(Node &node) {
		setLocation(node.location);
		setEntity(node.entity);
		setExploading(node.exploading);
		setNeighbors(node.neighbors);
	}

	Node operator= (Node &node) {
		setLocation(node.location);
		setEntity(node.entity);
		setExploading(node.exploading);
		setNeighbors(node.neighbors);
		
		return *this;
	}

	void setLocation(Location location) {
		this->location = location;
	}

	void setEntity(Entity entity) {
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

	Entity getEntity() {
		return entity;
	}

	bool isExploading() {
		return exploading;
	}

	vector<Node> getNeighbors() {
		return neighbors;
	}

private:
	Location location;
	Entity entity;
	bool exploading;
	vector<Node> neighbors;
};

