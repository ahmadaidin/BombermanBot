#pragma once

#include "../Header.h"
#include "../Map/MapHeader.h"
#include "../Map/Entities/EntitiesHeader.h"


class GreedyStrategy {
public:
	GreedyStrategy(char MyKey, string filePath) {
		map.setMap(MyKey, filePath);
		location = map.MyLocation;
	}

	vector<Location> getSurroundLocations() {
		vector<Location> surroundLocations;

		if (location.getAbsis() == 0) {
			//absis = 0
			if (location.getOrdinat() == 0) {
				//pojok kiri atas
				surroundLocations.push_back(location.getRight());
				surroundLocations.push_back(location.getRightDown());
				surroundLocations.push_back(location.getDown());
			}
			else if (location.getOrdinat() == map.Height - 1) {
				//pojok kiri bawah
				surroundLocations.push_back(location.getUp());
				surroundLocations.push_back(location.getRightUp());
				surroundLocations.push_back(location.getRight());
			}
			else {
				//sisi kiri
				surroundLocations.push_back(location.getUp());
				surroundLocations.push_back(location.getRightUp());
				surroundLocations.push_back(location.getRight());
				surroundLocations.push_back(location.getRightDown());
				surroundLocations.push_back(location.getDown());
			}
		}
		else if (location.getAbsis() == map.Width - 1) {
			//absis == map.width -1 
			if (location.getOrdinat() == 0) {
				//pojok kanan atas
				surroundLocations.push_back(location.getLeft());
				surroundLocations.push_back(location.getLeftDown());
				surroundLocations.push_back(location.getDown());
			}
			else if (location.getOrdinat() == map.Height - 1) {
				//pojok kanan bawah
				surroundLocations.push_back(location.getUp());
				surroundLocations.push_back(location.getLeftUp());
				surroundLocations.push_back(location.getLeft());
			}
			else {
				//sisi kanan
				surroundLocations.push_back(location.getUp());
				surroundLocations.push_back(location.getLeftUp());
				surroundLocations.push_back(location.getLeft());
				surroundLocations.push_back(location.getLeftDown());
				surroundLocations.push_back(location.getDown());
			}

		}
		else {
			//0< absis < map.width-1
			if (location.getOrdinat() == 0) {
				//sisi atas
				surroundLocations.push_back(location.getLeft());
				surroundLocations.push_back(location.getLeftDown());
				surroundLocations.push_back(location.getDown());
				surroundLocations.push_back(location.getRightDown());
				surroundLocations.push_back(location.getRight());
			}
			else if (location.getOrdinat() == map.Height - 1) {
				//sisi bawah
				surroundLocations.push_back(location.getLeft());
				surroundLocations.push_back(location.getLeftUp());
				surroundLocations.push_back(location.getUp());
				surroundLocations.push_back(location.getRightUp());
				surroundLocations.push_back(location.getRight());
			}
			else {
				//tengah-tengah
				surroundLocations.push_back(location.getUp());
				surroundLocations.push_back(location.getRightUp());
				surroundLocations.push_back(location.getRight());
				surroundLocations.push_back(location.getRightDown());
				surroundLocations.push_back(location.getDown());
				surroundLocations.push_back(location.getLeftDown());
				surroundLocations.push_back(location.getLeft());
				surroundLocations.push_back(location.getLeftUp());
			}
		}
		return surroundLocations;
	}

	vector<Location> getPossibleNextLoc() {
		vector<Location> locations;
		if (location.getAbsis() == 0) {
			//absis = 0
			if (location.getOrdinat() == 0) {
				//pojok kiri atas
				locations.push_back(location.getRight());
				locations.push_back(location.getDown());
			}
			else if (location.getOrdinat() == map.Height - 1) {
				//pojok kiri bawah
				locations.push_back(location.getUp());
				locations.push_back(location.getRight());
			}
			else {
				//sisi kiri
				locations.push_back(location.getUp());
				locations.push_back(location.getRight());
				locations.push_back(location.getDown());
			}
		}
		else if (location.getAbsis() == map.Width - 1) {
			//absis == map.width -1 
			if (location.getOrdinat() == 0) {
				//pojok kanan atas
				locations.push_back(location.getLeft());
				locations.push_back(location.getDown());
			}
			else if (location.getOrdinat() == map.Height - 1) {
				//pojok kanan bawah
				locations.push_back(location.getUp());
				locations.push_back(location.getLeft());
			}
			else {
				//sisi kanan
				locations.push_back(location.getUp());
				locations.push_back(location.getLeft());
				locations.push_back(location.getDown());
			}

		}
		else {
			//0< absis < map.width-1
			if (location.getOrdinat() == 0) {
				//sisi atas
				locations.push_back(location.getLeft());
				locations.push_back(location.getDown());
				locations.push_back(location.getRight());
			}
			else if (location.getOrdinat() == map.Height - 1) {
				//sisi bawah
				locations.push_back(location.getLeft());
				locations.push_back(location.getUp());
				locations.push_back(location.getRight());
			}
			else {
				//tengah-tengah
				locations.push_back(location.getUp());
				locations.push_back(location.getRight());
				locations.push_back(location.getDown());
				locations.push_back(location.getLeft());
			}
		}

		for (int i = 0; i<locations.size(); i++) {
			if (map.Entities[locations[i].getAbsis()][locations[i].getOrdinat()] == INDES_WALL
				|| map.Entities[locations[i].getAbsis()][locations[i].getOrdinat()] == DES_WALL
				|| map.Entities[locations[i].getAbsis()][locations[i].getOrdinat()] == BOMB
				|| map.Entities[locations[i].getAbsis()][locations[i].getOrdinat()] == PLAYER)
			{
				locations.erase(locations.begin() + i);
			}
		}
		return locations;
	}

	vector<Bomb> getSurroundBombs() {
		vector<Location> surroundLocations = getSurroundLocations();
		vector<Bomb> surroundBombs;
		for (int i = 0; i<surroundLocations.size(); i++) {
			Location l = surroundLocations[i];
			for (int j = 0; j<map.Bombs.size(); j++) {
				Location bombLoc = map.Bombs[j].getLocation();
				if (l.isEqual(bombLoc)) {
					surroundBombs.push_back(map.Bombs[j]);
				}
			}
		}
		return surroundBombs;
	}

	vector<Location> getSurroundBombsLoc() {
		vector<Location> surroundBombsLoc;
		vector<Location> surroundLocations = getSurroundLocations();
		for (int i = 0; i<surroundLocations.size(); i++) {
			if (map.Entities[surroundLocations[i].getAbsis()][surroundLocations[i].getOrdinat()] == BOMB) {
				Location bombLoc(surroundLocations[i]);
				surroundBombsLoc.push_back(bombLoc);
			}
		}
		return surroundBombsLoc;
	}


	vector<Location> getSurroundDesWall() {
		vector<Location> surroundDesWall;
		vector<Location> surroundLocations = getSurroundLocations();
		for (int i = 0; i<surroundLocations.size(); i++) {
			if (map.Entities[surroundLocations[i].getAbsis()][surroundLocations[i].getOrdinat()] == DES_WALL) {
				Location wallLoc(surroundLocations[i]);
				surroundDesWall.push_back(wallLoc);
			}
		}
		return surroundDesWall;
	}

	vector<Location> getSurroundEnemies() {
		vector<Location> surroundEnemies;
		vector<Location> surroundLocations = getSurroundLocations();
		for (int i = 0; i<surroundLocations.size(); i++) {
			if (map.Entities[surroundLocations[i].getAbsis()][surroundLocations[i].getOrdinat()] == PLAYER) {
				Location EnemiesLoc(surroundLocations[i]);
				surroundEnemies.push_back(EnemiesLoc);
			}
		}
		return surroundEnemies;
	}


	Location getTarget() {
		if (map.PowerUpsLoc.size() == 0) {
			return location.getNearestLocation(map.EnemiesLoc);
		}
		else {

			Location nearestEnemyLoc = location.getNearestLocation(map.EnemiesLoc);
			Location nearestPowerUpLoc = location.getNearestLocation(map.PowerUpsLoc);

			float distance1 = location.getDistance(nearestEnemyLoc);
			float distance2 = location.getDistance(nearestPowerUpLoc);
			if (distance1 >= distance2) {
				return nearestPowerUpLoc;
			}
			else {
				return nearestEnemyLoc;
			}
		}
	}

	vector<Location> getFeasibleNextLocation() {
		vector<Location> possibleNextLoc = getPossibleNextLoc();
		vector<Location> feasibleNextLoc;
		for (int i = 0; i<possibleNextLoc.size(); i++) {
			Location possNextLoc = possibleNextLoc[i];
			vector<Bomb> bombs = getSurroundBombs();
			if (bombs.size() == 0) {
				feasibleNextLoc.push_back(possNextLoc);
			}
		}
		return  feasibleNextLoc;
	}

	Location getNextStep() {
		vector<Location> feasibleNextLoc = getFeasibleNextLocation();
		if (feasibleNextLoc.size() == 0) {
			return location;
		}
		else {
			Location targetLocation = getTarget();
			Location nextStep = targetLocation.getNearestLocation(feasibleNextLoc);
			return nextStep;
		}
	}

	int getDecision() {
		if (getSurroundDesWall().size() != 0 || getSurroundEnemies().size() != 0) {
			return PLANT_BOMB;
		}
		else {
			Location nextStep = getNextStep();
			if (nextStep.isAbove(location)) {
				return MOVE_UP;
			}
			else if (nextStep.isRight(location)) {
				return MOVE_RIGHT;
			}
			else if (nextStep.isBelow(location)) {
				return MOVE_DOWN;
			}
			else if (nextStep.isLeft(location)) {
				return MOVE_LEFT;
			}
			else {
				return DO_NOTHING;
			}
		}
	}
private:
	Map map;
	Location location;
};