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

	vector<Location> getSurroundLocations(Location location) {
		vector<Location> surroundLocations;

		if (location.getAbsis() == 0) {
			//sisi kiri
			if (location.getOrdinat() == 0) {
				//pojok kiri atas
				surroundLocations.push_back(location.getRight());
			//	surroundLocations.push_back(location.getRightDown());
				surroundLocations.push_back(location.getDown());
			}
			else if (location.getOrdinat() == map.Height - 1) {
				//pojok kiri bawah
				surroundLocations.push_back(location.getUp());
				//surroundLocations.push_back(location.getRightUp());
				surroundLocations.push_back(location.getRight());
			}
			else {
				//sisi kiri tengah
				surroundLocations.push_back(location.getUp());
				//surroundLocations.push_back(location.getRightUp());
				surroundLocations.push_back(location.getRight());
				//surroundLocations.push_back(location.getRightDown());
				surroundLocations.push_back(location.getDown());
			}
		}
		else if (location.getAbsis() == map.Width - 1) {
			//absis == sisi kanan 
			if (location.getOrdinat() == 0) {
				//pojok kanan atas
				surroundLocations.push_back(location.getLeft());
				//surroundLocations.push_back(location.getLeftDown());
				surroundLocations.push_back(location.getDown());
			}
			else if (location.getOrdinat() == map.Height - 1) {
				//pojok kanan bawah
				surroundLocations.push_back(location.getUp());
				//surroundLocations.push_back(location.getLeftUp());
				surroundLocations.push_back(location.getLeft());
			}
			else {
				//sisi kanan tengah
				surroundLocations.push_back(location.getUp());
				//surroundLocations.push_back(location.getLeftUp());
				surroundLocations.push_back(location.getLeft());
				//surroundLocations.push_back(location.getLeftDown());
				surroundLocations.push_back(location.getDown());
			}
		}
		else {
			//bagian tengah
			if (location.getOrdinat() == 0) {
				//sisi atas tengah
				surroundLocations.push_back(location.getLeft());
				//surroundLocations.push_back(location.getLeftDown());
				surroundLocations.push_back(location.getDown());
				//surroundLocations.push_back(location.getRightDown());
				surroundLocations.push_back(location.getRight());
			}
			else if (location.getOrdinat() == map.Height - 1) {
				//sisi bawah tengah
				surroundLocations.push_back(location.getLeft());
				//surroundLocations.push_back(location.getLeftUp());
				surroundLocations.push_back(location.getUp());
				//surroundLocations.push_back(location.getRightUp());
				surroundLocations.push_back(location.getRight());
			}
			else {
				//tengah-tengah
				surroundLocations.push_back(location.getUp());
				//surroundLocations.push_back(location.getRightUp());
				surroundLocations.push_back(location.getRight());
				//surroundLocations.push_back(location.getRightDown());
				surroundLocations.push_back(location.getDown());
				//surroundLocations.push_back(location.getLeftDown());
				surroundLocations.push_back(location.getLeft());
				//surroundLocations.push_back(location.getLeftUp());
			}
		}
		//surroundLocations.push_back(location);
		return surroundLocations;
	}

	vector<Location> getPossibleNextLoc(Location location) {
		vector<Location> locations;
		vector<Location> surroundLocations = getSurroundLocations(location);
		for (int i = 0; i < surroundLocations.size(); i++) {
			Location surLoc = surroundLocations[i];
			//if (location.getDirection(surroundLocations[i]) != DIAGONAL) {
				if (map.Entities[surLoc.getAbsis()][surLoc.getOrdinat()] != INDES_WALL
					&& map.Entities[surLoc.getAbsis()][surLoc.getOrdinat()] != DES_WALL
					&& map.Entities[surLoc.getAbsis()][surLoc.getOrdinat()] != BOMB
					&& map.Entities[surLoc.getAbsis()][surLoc.getOrdinat()] != PLAYER)
				{
					locations.push_back(surLoc);
				}
			//}
		}

/*		for (int i = 0; i<locations.size(); i++) {
			if (map.Entities[locations[i].getAbsis()][locations[i].getOrdinat()] == INDES_WALL
				|| map.Entities[locations[i].getAbsis()][locations[i].getOrdinat()] == DES_WALL
				|| map.Entities[locations[i].getAbsis()][locations[i].getOrdinat()] == BOMB
				|| map.Entities[locations[i].getAbsis()][locations[i].getOrdinat()] == PLAYER)
			{
				locations.erase(locations.begin() + i);
			}
		}*/
		return locations;
	}

	bool isBuntu(Location nextLocation) {
		return getFeasibleNextLocation(nextLocation).size() == 0;
	}

	vector<Bomb> getSurroundBombs(Location location) {
		vector<Location> surroundLocations = getSurroundLocations(location);
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

	vector<Location> getSurroundBombsLoc(Location location) {
		vector<Location> surroundBombsLoc;
		vector<Location> surroundLocations = getSurroundLocations(location);
		for (int i = 0; i<surroundLocations.size(); i++) {
			if (map.Entities[surroundLocations[i].getAbsis()][surroundLocations[i].getOrdinat()] == BOMB) {
				Location bombLoc(surroundLocations[i]);
				surroundBombsLoc.push_back(bombLoc);
			}
		}
		return surroundBombsLoc;
	}


	vector<Location> getSurroundDesWall(Location location) {
		vector<Location> surroundDesWall;
		vector<Location> surroundLocations = getSurroundLocations(location);
		for (int i = 0; i<surroundLocations.size(); i++) {
			Location surroundLocation = surroundLocations[i];
			string type = map.Entities[surroundLocation.getAbsis()][surroundLocation.getOrdinat()];
			if (type == DES_WALL) {
				surroundDesWall.push_back(surroundLocation);
			}
		}
		return surroundDesWall;
	}

	vector<Location> getSurroundEnemies(Location location) {
		vector<Location> surroundEnemies;
		vector<Location> surroundLocations = getSurroundLocations(location);
		for (int i = 0; i<surroundLocations.size(); i++) {
			if (map.Entities[surroundLocations[i].getAbsis()][surroundLocations[i].getOrdinat()] == PLAYER) {
				Location enemiesLoc = surroundLocations[i];
				surroundEnemies.push_back(enemiesLoc);
			}
		}
		return surroundEnemies;
	}


	Location getTarget(Location location) {
		if (map.PowerUpsLoc.size() == 0) {
			return location.getNearestLocation(map.EnemiesLoc);
		}
		else {
			Location nearestEnemyLoc = location.getNearestLocation(map.EnemiesLoc);
			Location nearestPowerUpLoc = location.getNearestLocation(map.PowerUpsLoc);

			float distance1 = location.getDistance(nearestEnemyLoc);
			float distance2 = location.getDistance(nearestPowerUpLoc);
			if (distance1 <= distance2) {
				return nearestPowerUpLoc;
			}
			else {
				return nearestEnemyLoc;
			}
		}
	}

	vector<Location> getFeasibleNextLocation(Location location) {
		vector<Location> possibleNextLoc = getPossibleNextLoc(location);
		vector<Location> feasibleNextLoc;
		vector<Location> bombNearToMe = getSurroundBombsLoc(location);
		bool isBombInMyLoc = (map.Entities[location.getAbsis()][location.getOrdinat()] == BOMB);

		if (isBombInMyLoc) {
			for (int i = 0; i < possibleNextLoc.size(); i++) {
				Location possNextLoc = possibleNextLoc[i];
				if (!isBuntu(possNextLoc)) {
					feasibleNextLoc.push_back(possNextLoc);
				}
			}
		} else if (bombNearToMe.size() != 0) {
			for (int i = 0; i < possibleNextLoc.size(); i++) {
				Location possNextLoc = possibleNextLoc[i];
				//if (!isBuntu(possNextLoc)) {
					feasibleNextLoc.push_back(possNextLoc);
				//}
			}
			
			if (feasibleNextLoc.size() != 0) {
				Location minBombNearLoc = feasibleNextLoc[0];
				int minBombNear = getSurroundBombsLoc(minBombNearLoc).size();
				for (int i = 1; i<feasibleNextLoc.size(); i++) {
					Location bombNearLoc = feasibleNextLoc[i];
					int numBomNear = getSurroundBombsLoc(bombNearLoc).size();
					if (numBomNear < minBombNear) {
						minBombNear = numBomNear;
						minBombNearLoc = bombNearLoc;
					}
				}
				feasibleNextLoc.clear();
				feasibleNextLoc.push_back(minBombNearLoc);
			}
		}
		else {
			for (int i = 0; i<possibleNextLoc.size(); i++) {
				Location possNextLoc = possibleNextLoc[i];
				vector<Location> bombsLoc = getSurroundBombsLoc(possNextLoc);
				if (bombsLoc.size() == 0) {
					//if (!isBuntu(possNextLoc)) {
						feasibleNextLoc.push_back(possNextLoc);
					//}
				}
			}
		}
		return  feasibleNextLoc;
	}

	Location getNextStep(Location location) {
		vector<Location> feasibleNextLoc = getFeasibleNextLocation(location);
		if (feasibleNextLoc.size() == 0) {
			return location;
		}
		else {
			Location targetLocation = getTarget(location);
			Location nextStep = targetLocation.getNearestLocation(feasibleNextLoc);
			return nextStep;
		}
	}

	int getDecision() {
		vector<Location> surroundDesWall = getSurroundDesWall(location);
		vector<Location> surroundEnemies = getSurroundEnemies(location);
		if ( surroundDesWall.size()!= 0 || surroundEnemies.size() != 0) {
			bool noBombs = true;
			int i= 0;
			while (noBombs && i < surroundDesWall.size()) {
				if (getSurroundBombsLoc(surroundDesWall[i]).size() != 0) {
					noBombs = false;
				}
				i++;
			}
			i = 0;
			while (noBombs && i < surroundEnemies.size()) {
				if (getSurroundBombsLoc(surroundEnemies[i]).size() != 0) {
					noBombs = false;
				}
				i++;
			}

			if (noBombs && map.BombBag>0) {
				return PLANT_BOMB;
			}
			else {
				return getStepDecision(location);
			}
		}
		else {
			return getStepDecision(location);
		}
	}

	int getStepDecision(Location location) {
		Location nextStep = getNextStep(location);
		string direction = nextStep.getDirection(location);
		if (direction == ABOVE) {
			return MOVE_UP;
		}
		else if (direction == RIGHT) {
			return MOVE_RIGHT;
		}
		else if (direction == BELOW) {
			return MOVE_DOWN;
		}
		else if (direction == LEFT) {
			return MOVE_LEFT;
		}
		else {
			return DO_NOTHING;
		}
	}

	Map map;
	Location location;
};