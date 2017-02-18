#include <random>
#include "stdafx.h"
#include "json.hpp"
#include "Map/Entities/EntitiesHeader.h"
#include "Map/Entities/PowerUp/PowerUpHeader.h"
#include "Map/MapHeader.h"

using namespace std;
using namespace nlohmann;

//string readStateFile(string filePath);
//void writeMoveFile(string filePath);

int main() {
/*	string filePath = "roundInfo.json";
	cout << "Reading state file state.json" << std::endl;
	//string jsonString = readStateFile(filePath);
	json jsonString = readStateFile(filePath);
	auto j = R"("+jsonString+")"_json;
	cout << jsonString["MapSeed"]<< endl;
	//cout << jsonString["RegisteredPlayerEntities"]<< endl;
	*/
	
	vector<Block> blocks(5);
	
	Location l1(1,9); 
	Location l2(2, 3);
	Location l3(3, 1);
	Location l4(4, 9);
	Location l5(5, 8);
	Location l6(6, 6);
	Location l7(7, 4);
	Location l8(8, 2);
	Location l9(9, 9);

/*	BombBagPowerUp *bbpu1= new BombBagPowerUp(l1);
	BombBagPowerUp *bbpu2= new BombBagPowerUp(*bbpu1);
	bbpu1->setLocation(l2);
	SuperPowerUp *spu1= new SuperPowerUp(l3);
	SuperPowerUp *spu2 = new SuperPowerUp(*spu1);
	spu2->setLocation(l4);
	BombRadiusPowerUp *brpu = new BombRadiusPowerUp(l5);
	Player *p1 = new Player(l6, "Aidin", 'A', 100, 10, 5);
	Player *p2 = new Player(*p1);
	p2->setName("Rudi");
	Bomb *bomb = new Bomb(l7, *p1, 10, 10, 0, 80);
	DestructibleWall *dw= new DestructibleWall(l8);
	IndestructibleWall *idw = new IndestructibleWall(l9);*/

	BombBagPowerUp bbpu1(l1);
	BombBagPowerUp bbpu2 = bbpu1;
	bbpu1.setLocation(l2);
	SuperPowerUp spu1(l3);
	SuperPowerUp spu2(spu1);
	spu2.setLocation(l4);
	BombRadiusPowerUp brpu(l6);
	Player p1(l6, "Aidin", 'A', 100, 10, 5);
	Player p2=p1;
	p2.setName("Rudi");
	Bomb bomb(l7,p1, 10, 10, 0, 80);
	DestructibleWall dw(l8);
	IndestructibleWall idw(l9);
	
	//Block b1(l1, p1, bomb, brpu, 0);
	//Block b2;
	//b2.setLocation(l2);
	//b2.setExploading(1);
	//Block b3;
	//b3.setLocation(l3);


	return 0;
}



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

void writeMoveFile(string filePath)
{
	cout << "Writing move file " << filePath + "/" + "move.txt" << std::endl;
	ofstream outfile(filePath + "/" + "move.txt");

	if (outfile.is_open())
	{
	//	random_device rd;
	//	mt19937 rng(rd());
	//	uniform_int_distribution<int> uni(1, 6);
	//	outfile << uni(rng) << std::endl;
		outfile << 4 << std::endl;
		outfile.close();
	}
}

*/