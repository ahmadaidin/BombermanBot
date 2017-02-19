//File : Greedy.hpp

#include "../Map/MapHeader.h"
#include "../Map/Entities/EntitiesHeader.h"
#include "../Map/Entities/Player.hpp"
#include <iostream>
#include <math.h>
using namespace std;

float Distance(Location P, Location V) {
	float XP = (float)P.getAbsis();
	float YP = (float)P.getOrdinat();
	float X = (float) V.getAbsis();
	float Y = (float) V.getOrdinat();
	return sqrt(abs((XP - X)*(XP - X) + (YP - Y)*(YP - Y)));
}

int ClosestDistance(Location P, vector<Location> V) {
	float Min = Distance(P, V[0]);
	int IdxMin = 0;
	for (int i = 1; i < V.size; i++) {
		if (Min < Distance(P, V[i])) {
			Min = Distance(P, V[i]);
			IdxMin = i;
		}
	}
	return IdxMin;
}

Location ClosestLocation(Location P, vector<Location> V) {
	return V[ClosestDistance(P, V)];
}

int Player::NextLocation(vector<Location> VPowerUp, vector<Location> VEnemy) {
	int Decision;
	Location Self = getLocation();
	Location ClosestEntity;
	if (getBombBag() != 0) {
		if (VPowerUp.empty()) {
			//Cari Enemy Terdekat
			ClosestEntity = ClosestLocation(Self, VEnemy);
		}
		else {
			//Cari Powerup dan Enemy Terdekat
			ClosestEntity = ClosestLocation(Self, VPowerUp);
			ClosestEntity = ClosestLocation(Self, VEnemy);
		}
	}
	else {
		if (VPowerUp.empty()) {
			//Ke Tengah
			//Closest Entity
			ClosestEntity = ClosestLocation(Self, VPowerUp);
		}
		else {
			//Cari Powerup Terdekat atau Ke Tengah
			ClosestEntity = ClosestLocation(Self, VPowerUp);
		}
	}
	if (ClosestEntity.getAbsis() - Self.getAbsis() <= ClosestEntity.getOrdinat() - Self.getOrdinat()) {
		if (ClosestEntity.getAbsis() < Self.getAbsis()) {
			Decision = 2;
		}
		else if (ClosestEntity.getAbsis() > Self.getAbsis()) {
			Decision = 3;
		}
		else {
			Decision = 7;
		}
	}
	else {
		if (ClosestEntity.getOrdinat() < Self.getOrdinat()) {
			Decision = 4;
		}
		else if (ClosestEntity.getOrdinat() > Self.getOrdinat()) {
			Decision = 1;
		}
		else {
			Decision = 7;
		}
	}
	return Decision;
}