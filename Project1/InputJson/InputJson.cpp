
#include <iostream>
#include <string>
#include "json.h"
#include <fstream>
#include "../Map/Entities/PowerUp/PowerUpHeader.h"
#include "../Map/Entities/EntitiesHeader.h"
#include "../Map/MapHeader.h"

using namespace std;
using namespace Json;

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

vector<vector<Block>> GetAllGameBlock(Json::Value obj){
	vector<vector<Block>> allBlock;
	Json::Value B = obj["GameBlocks"];

	for (int i = 0; i < B.size(); i++) {
		vector<Block> rowBlock;
		for (int j = 0; j < B[i].size(); j++) {
			Json::Value jBlock = B[i][j];
			Block block;
			Json::Value jEntity = jBlock["Entity"];
			if (jEntity.isNull()) {

			}
			else {
				string type = jEntity["$type"].asString();
				Location location(jEntity["Location"]["X"].asInt(), jEntity["Location"]["Y"].asInt());
				if (type == DES_WALL) {
					DestructibleWall *destructibleWall = new DestructibleWall(location);
					block.setEntity(destructibleWall);
				}
				else if (type == INDES_WALL) {
					IndestructibleWall *indestructibleWall = new IndestructibleWall(location);
					block.setEntity(indestructibleWall);
				}
				else if (type == PLAYER) {
					Player *player = new Player();
					player->setName(jEntity["Name"].asString());
					player->setKey(jEntity["Key"].asString()[0]);
					player->setPoint(jEntity["Points"].asInt());
					player->setKilled(jEntity["Killed"].asBool());
					player->setBombag(jEntity["BombBag"].asInt());
					player->setBombRadius(jEntity["BombRadius"].asInt());
					player->setLocation(location);

					block.setEntity(player);
				}
				else {

				}

			}

			Json::Value jBomb = jBlock["Bomb"];
			if (jBomb.isNull()) {

			}
			else {
				Value jBombOwner = jEntity["Owner"];
				Location jOwnerLocation(jBombOwner["Location"]["X"].asInt(), jBombOwner["Location"]["Y"].asInt());
				Player owner;
				owner.setName(jBombOwner["Name"].asString());
				owner.setKey(jBombOwner["Key"].asString()[0]);
				owner.setPoint(jBombOwner["Points"].asInt());
				owner.setKilled(jBombOwner["Killed"].asBool());
				owner.setBombag(jBombOwner["BombBag"].asInt());
				owner.setBombRadius(jBombOwner["BombRadius"].asInt());
				owner.setLocation(jOwnerLocation);

				int bombRadius = jBomb["BombRadius"].asInt();
				int bombTimer = jBomb["BombTimer"].asInt();
				bool isExploding = jBomb["IsExploding"].asBool();
				Location bombLocation(jBomb["Location"]["X"].asInt(), jBomb["Location"]["Y"].asInt());


				Bomb *bomb = new Bomb(bombLocation, owner, bombTimer, isExploding, bombRadius);
				block.setBomb(bomb);
			}
			Value jPowerUp = jBlock["PowerUp"];
			if (jPowerUp.isNull()) {

			}
			else {
				string type = jPowerUp["$type"].asString();
				Location powerUPLocation(jPowerUp["Location"]["X"].asInt(), jPowerUp["Location"]["Y"].asInt());

				if (type == SUPER_POW_UP) {
					SuperPowerUp *superPU = new SuperPowerUp(powerUPLocation);
					block.setPowerUp(superPU);
				}
				else if (type == BOMB_BAG_POW_UP) {
					BombBagPowerUp *bombBagPU = new BombBagPowerUp(powerUPLocation);
					block.setPowerUp(bombBagPU);
				}
				else if (type == BOMB_RAD_POW_UP) {
					BombRadiusPowerUp *bombRadiusPU = new BombRadiusPowerUp(powerUPLocation);
					block.setPowerUp(bombRadiusPU);
				}
			}

			bool exploding = jBlock["Exploding"].asBool();
			Location blockLocation(jBlock["Location"]["X"].asInt(), jBlock["Location"]["Y"].asInt());
			block.setExploding(exploding);
			block.setLocation(blockLocation);
			
			rowBlock.push_back(block);
		}
		allBlock.push_back(rowBlock);
	}
	return allBlock;
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
 
  vector<Player> players = getAllPlayer(obj);
  vector<vector<Block>> blocks = GetAllGameBlock(obj);
  cout << getCurrentRound(obj) << endl;
  cout << getPlayerBounty(obj) << endl;
  cout << MapHeight(obj) << endl;
  cout << MapWidth(obj) << endl;
  for (int i = 0; i < players.size(); i++) {
	  cout << players[i].toString() << endl;
  }
  cout << "YELLBOYS" << endl;
  for (int i = 0; i < blocks.size(); i++) {
	  for (int j = 0; j < blocks[i].size(); j++) {
		  if (blocks[i][j].isNullEntity()) {

		  } else {
			  cout << blocks[i][j].getEntity().getPossiblePoints() << endl;
			//cout << blocks[i][j].getLocation().getAbsis() << " " << blocks[i][j].getLocation().getOrdinat();
		  }
	  }
  }
  cout<<"Haha"<<endl;
  return 0;
}