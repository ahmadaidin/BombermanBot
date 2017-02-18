
#include <iostream>
#include <string>
#include "json.h"
#include <fstream>
#include "../Map/Entities/PowerUp/PowerUpHeader.h"
#include "../Map/Entities/EntitiesHeader.h"
#include "../Map/MapHeader.h"

using namespace std;

string ReadJson(string filePath) {
	cout << "Reading state file " << filePath << endl;
	string fileContent;
	string line;
	ifstream myfile(filePath);
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

vector<Player> getAllPlayer(Json::Value obj){
	vector<Player> allPlayer;
	Json::Value REP = obj["RegisteredPlayerEntities"];
	for (int i = 0; i < REP.size(); i++) {
		string name = REP[i]["Name"].asString();
		char key = REP[i]["Key"].asString()[0];
		int points = REP[i]["Points"].asInt();
		int BombBag = REP[i]["BombBag"].asInt();
		int BombRadius = REP[i]["BombRadius"].asInt();
		int x = REP[i]["Location"]["X"].asInt();
		int y = REP[i]["Location"]["Y"].asInt();
		Location location(x, y);
		Player p(location, name, key, points, BombBag, BombRadius);
		allPlayer.push_back(p);
	}
	return allPlayer;
}

int getCurrentRound(Json::Value obj){
	return obj["CurrentRound"].asInt();
}

int getPlayerBounty(Json::Value obj){
	return obj["PlayerBounty"].asInt();
}
	
int MapHeight(Json::Value obj){
	return obj["MapHeight"].asInt();
}

int MapWidth(Json::Value obj){
	return obj["MapWidth"].asInt();
}

void GetAllGameBlock(Json::Value obj){
	vector<vector<Block>> allBlock;
	Json::Value B = obj["GameBlocks"];

	for (int i = 0; i < B.size(); i++) {
		for (int j = 0; j < B[i].size(); j++) {
			Location blockLocation(i+1, j+1);
			Block block(blockLocation);
			Json::Value entity = B[i][j]["Entity"];
			if (entity.isNull()) {

			}
			else {
				string type = entity["$type"].asString();
				Location location(entity["Location"]["X"].asInt(), entity["Location"]["Y"].asInt());
				if (type == DES_WALL) {
					DestructibleWall *destructibleWall= new DestructibleWall(location);
					block.setEntity(destructibleWall);
				}
				else if (type == INDES_WALL) {
					IndestructibleWall *indestructibleWall = new IndestructibleWall(location);
					block.setEntity(indestructibleWall);
				}
				else if (type == PLAYER) {
					Player *player = new Player();
					player->setName(entity["Name"].asString());
					player->setKey(entity["Key"].asString()[0]);
					player->setPoint(entity["Points"].asInt());
					player->setKilled(entity["Killed"].asBool());
					player->setBombag(entity["BombBag"].asInt());
					player->setBombRadius(entity["BombRadius"].asInt());
					player->setLocation(location);

					block.setEntity(player);
				}
				else if (type == SUPER_POW_UP) {
					SuperPowerUp *superPU = new SuperPowerUp(location);
					block.setEntity(superPU);
				}
				else if (type == BOMB_BAG_POW_UP) {
					BombBagPowerUp *bombBagPU = new BombBagPowerUp(location);
					block.setEntity(bombBagPU);
				}
				else if (type == BOMB_RAD_POW_UP){
					BombRadiusPowerUp *bombRadiusPU = new BombRadiusPowerUp(location);
					block.setEntity(bombRadiusPU);
				}
				else {
					
				}
			}
			
			/*if (type == "null") {

			}
			int x1 = B[i]["X"].asInt();
			int y1 = B[i]["Y"].asInt();
			Location Loc1(x1,y1);

			Entity entity(Loc1);

			if (!obj["Bomb"].isnull()) {
				string name = B[i]["Name"].asString();
				char key = B[i]["Key"].asCString();
				int points = B[i]["Points"].asInt();
				bool killed = B[i]["Killed"].asBool();
				int BombBag= B[i]["BombBag"].asInt();
				int BombRadius= B[i]["BombRadius"].asInt();
				int x3 = B[i]["X"].asInt();
				int y3 = B[i]["Y"].asInt();
				Location Loc3(x3,y3);
				Player owner(loc3, name, key, points, BombBag, BombRadius);
				int BombRadius= B[i]["BombRadius"].asInt();
				int BombTimer= B[i]["BombTimer"].asInt();
				bool IsExploding= B[i]["IsExploding"].asBool();
				int x4 = B[i]["X"].asInt();
				int y4 = B[i]["Y"].asInt();
				Location Loc4(x4,y4);
				Bomb bomb(Loc4, owner, BombTimer, IsExploding, BombRadius);
			}

			if (!(obj["PowerUp"].isnull())) {
				string type = B[i]["$type"].asString();
				int x5 = B[i]["X"].asInt();
				int y5 = B[i]["Y"].asInt();
				Location Loc5(x5,y5);
				PowerUp * powerup(type, Loc5);
			}

			string P = B[i]["PowerUp"].asString();
			bool e = B[i]["Exploding"].asBool();
			int x2= B[i]["X"].asInt();
			int y2 = B[i]["Y"].asInt();
			Location Loc2(x2,y2);*/
		}
	}

	//Block *b = new Block(Loc2, entity, Bomb, PowerUp);
	//allBlock.push_back(*b);

	//return allBlock;
}

double MapSeed(Json::Value obj) {
	return obj["MapSeed"].asDouble();
}

int main() {
  string str;
  str = ReadJson("state.json");
  Json::Reader reader;
  Json::Value obj;
  reader.parse(str, obj);
  GetAllGameBlock(obj);
  cout<<"Haha"<<endl;
  return 0;
}