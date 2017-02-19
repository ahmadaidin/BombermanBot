#include <random>
#include "stdafx.h"
#include "Strategies\GreedyStrategy.hpp"

using namespace std;

//string readStateFile(string filePath);
 
void writeMoveFile(string filePath, int decision);

 /*
int main() {
	string filePath = "state.json";

	Map map('A', filePath);
	int MapHeight = map.MapHeight;
	int MapWidth = map.MapWidth;
	double MapSeed = map.MapSeed;

	vector<Player> Players = map.Players;
	vector<Bomb> Bombs = map.Bombs;
	vector<vector<string>> Entities = map.Entities;

	vector<Location> EnemiesLoc = map.EnemiesLoc;
	vector<Location> PowerUpsLoc = map.PowerUpsLoc;
	vector<Location> IndestructibleWallLoc = map.IndestructibleWallLoc;
	vector<Location> DestructibleWallsLoc = map.DestructibleWallsLoc;
	vector<Location> ExplodingLoc = map.ExplodingLoc;
	vector<Location> BombsLoc = map.BombsLoc;



	cout << "===================================" << endl;
	cout << "All Players" << endl;
	for (int i = 0; i < Players.size(); i++) {
		cout << Players[i].toString() << endl;
	}

	cout << "===================================" << endl;
	cout << "All Bombs" << endl;	for (int i = 0; i < Bombs.size(); i++) {
		cout << Bombs[i].toString() << endl;
	}

	cout << "===================================" << endl;
	cout << "All Entities" << endl;
	for (int i = 0; i < Entities.size(); i++) {
		for (int j = 0; j < Entities[i].size(); j++) {
			cout << Entities[i][j] << endl;
		}
	}

	cout << "===================================" << endl;
	cout << "All Enemies" << endl;
	for (int i = 0; i < EnemiesLoc.size(); i++) {
		cout << EnemiesLoc[i].toString() << endl;
	}

	cout << "===================================" << endl;
	cout << "All PowerUps" << endl;
	for (int i = 0; i < PowerUpsLoc.size(); i++) {
		cout << PowerUpsLoc[i].toString() << endl;
	}

	cout << "===================================" << endl;
	cout << "All Indestructible Wall" << endl;
	for (int i = 0; i < IndestructibleWallLoc.size(); i++) {
		cout << IndestructibleWallLoc[i].toString() << endl;
	}
	
	cout << "===================================" << endl;
	cout << "All Destructible Wall" << endl;
	for (int i = 0; i < DestructibleWallsLoc.size(); i++) {
		cout << DestructibleWallsLoc[i].toString() << endl;
	}

	cout << "===================================" << endl;
	cout << "All Exploding block" << endl;
	for (int i = 0; i < ExplodingLoc.size(); i++) {
		cout << ExplodingLoc[i].toString() << endl;
	}

	cout << "===================================" << endl;
	cout << "All Bombs" << endl;
	for (int i = 0; i < BombsLoc.size(); i++) {
		cout << BombsLoc[i].toString() << endl;
	}
	
	return 0;
}

*/

/*string readStateFile(string filePath)
{
	cout << "Reading state file " << filePath + "/" + "state.json" << std::endl;
	string fileContent;
	string line;
	ifstream myfile(filePath + "/" + "state.json");

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			fileContent += line += "\n";
		}
		myfile.close();
	}

	return fileContent;
}
*/

int _tmain(int argc, _TCHAR* argv[])
{
	string filePath = argv[2];

	cout << "Args: " << argc << std::endl;
	cout << "Player Key: " << argv[1] << std::endl;
	cout << "File Path: " << argv[2] << std::endl;

	char playerKey = argv[1][0];
	string inputFile = filePath + "/"+"state.json";
	string outputFile = filePath + "/" + "move.txt";
	GreedyStrategy greedy(playerKey, filePath);
	int decision = greedy.getDecision();
	writeMoveFile(outputFile, decision);
	return 0;
}

void writeMoveFile(string filePath, int decision)
{
	cout << "Writing move file " << filePath << std::endl;
	ofstream outfile(filePath);

	if (outfile.is_open())
	{
		outfile << decision << std::endl;
		outfile.close();
	}
}