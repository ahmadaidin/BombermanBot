#include <random>
#include "stdafx.h"
#include "Strategies\GreedyStrategy.hpp"

using namespace std;

//string readStateFile(string filePath);

void writeMoveFile(string filePath, int decision);


int main() {
	string filePath = "state.json";
	char playerKey = 'A';
	GreedyStrategy greedy(playerKey,filePath);
	
	Location myLocation = greedy.location;
	Location location = greedy.location;
	Location loc = greedy.location;

	cout << "My Location: " << myLocation.toString() << endl;
	cout << "==========================" << endl;
	cout << "surround Location :" << endl;



	vector<Location> l2 = greedy.getSurroundLocations(loc);
	for (int i = 0; i < l2.size(); i++) {
		cout << l2[i].toString() << endl;
	}

	cout << "==========================" << endl;
	cout << "surround Des Wall :" << endl;
	
	vector<Location> l1 = greedy.getSurroundDesWall(loc);
	for (int i = 0; i < l1.size(); i++) {
		cout << l1[i].toString() << endl;
		string opo = greedy.map.Entities[l1[i].getAbsis()][l1[i].getOrdinat()];
		cout << opo << endl;	
	}

	cout << "==========================" << endl;
	cout << "possible Next Loc :" << endl;

	vector<Location> l = greedy.getPossibleNextLoc(loc);
	for (int i = 0; i < l.size(); i++) {
		cout << l[i].toString() << " - ";
		cout << l[i].getDirection(greedy.location) << " - ";
		string opo = greedy.map.Entities[l[i].getAbsis()][l[i].getOrdinat()];
		cout << opo << endl;
	}
	
	cout << "==========================" << endl;
	cout << "surround Enemy :" << endl;
	vector<Location> l4 = greedy.getSurroundEnemies(location);
	for (int i = 0; i < l4.size(); i++) {
		cout << l4[i].toString() << endl;
	}

	cout << "==========================" << endl;
	cout << "surround Bomb Loc" << endl;
	vector<Location> l5 = greedy.getSurroundBombsLoc(location);
	for (int i = 0; i < l5.size(); i++) {
		cout << l5[i].toString() << endl;
	}

	cout << "==========================" << endl;
	cout << "Feasible next" << endl;
	vector<Location> l6 = greedy.getFeasibleNextLocation(loc);
	for (int i = 0; i < l6.size(); i++) {
		cout << l6[i].toString() << "-"<<greedy.map.Entities[l6[i].getAbsis()][l6[i].getOrdinat()]<<endl;
		cout << "==========================" << endl;
		cout << "surround Bomb Loc" << endl;
		vector<Location> loooc = greedy.getSurroundBombsLoc(l6[i]);
		for (int i = 0; i < loooc.size(); i++) {
			cout << loooc[i].toString() << endl;
		}
	}

	


	cout << "==========================" << endl;
	cout << "target" << endl;
	Location l7 = greedy.getTarget(loc);
	cout << l7.toString() << endl;
	cout << "decision : "<<greedy.getDecision() << endl;

	cout << "lokasiku:" << loc.toString() << endl;
	
	cout << "isi lokasi ku: " << endl;	
	Location myLoc = greedy.map.MyLocation;
	cout << greedy.map.Entities[myLoc.getAbsis()][myLoc.getOrdinat()] << endl;
}

