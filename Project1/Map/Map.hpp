#pragma once

/*class Map {
public:
	Map() {
		
	}

	Map(int seed, int height, int width) {
		this->seed = seed;
		this->height = height;
		this->width = width;
	}

	Map& operator= (Map &map) {
		setSeed(map.seed);
		setHeight(map.height);
		setWidth(map.width);
		setBlocks(map.blocks);
		return *this;
	}

	void fromJson(string map) {

	}

	Block getBlockAt(int x, int y) {
		return blocks[x-1][y-1];
	}

	void setSeed(int seed) {
		this->seed = seed;
	}

	void setHeight(int height) {
		this->height = height;
	}

	void setWidth(int width) {
		this->width = width;
	}

	void setBlocks(vector<vector<Block>> blocks) {
		this->blocks.clear();
		for (int i = 0; i < blocks.size(); i++) {
			this->blocks.push_back(blocks[i]);
		}
	}

	int getSeed() {
		return seed;
	}

	int getHeight() {
		return height;
	}

	int getWidth() {
		return width;
	}

	vector<vector<Block>> getBlocks() {
		return blocks;
	}

private:
	int seed;
	int height;
	int width;
	vector<vector<Block>> blocks;
};
*/

//#pragma once


#include <iostream>
#include <string>
#include "../InputJson/json.h"
#include <fstream>
//#include "Entities/PowerUp/PowerUpHeader.h"
#include "Entities/EntitiesHeader.h"
#include "MapHeader.h"

using namespace std;
using namespace Json;

class Map {
public:
	Map(char myKey, string filePath) {
		this->MyKey = myKey;
		string str = ReadJson(filePath);
		Json::Reader reader;
		Json::Value obj;
		reader.parse(str, obj);
		MapSeed = obj["MapSeed"].asDouble();

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
			Players.push_back(p);
		}

		Json::Value B = obj["GameBlocks"];

		for (int i = 0; i < B.size(); i++) {
			vector<string> rowBlock;
			for (int j = 0; j < B[i].size(); j++) {
				Json::Value jBlock = B[i][j];
				//Block block;
				string entity="null";
				Json::Value jEntity = jBlock["Entity"];
				if (jEntity.isNull()) {
//					entity = "null";
				}
				else {
					string type = jEntity["$type"].asString();
					Location location(jEntity["Location"]["X"].asInt(), jEntity["Location"]["Y"].asInt());
					if (type == DES_WALL) {
						entity = DES_WALL;
						DestructibleWallsLoc.push_back(location);
					}
					else if (type == INDES_WALL) {
						entity = INDES_WALL;
						IndestructibleWallLoc.push_back(location);
					}
					else if (type == PLAYER) {
						string key = (jEntity["Key"].asString());
						entity = key;
						if (MyKey != key[0]) {
							EnemiesLoc.push_back(location);
						}
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
					int bombRadius = jBomb["BombRadius"].asInt();
					int bombTimer = jBomb["BombTimer"].asInt();
					bool isExploding = jBomb["IsExploding"].asBool();
					Location bombLocation(jBomb["Location"]["X"].asInt(), jBomb["Location"]["Y"].asInt());
					Bomb bomb(bombLocation, owner, bombTimer, isExploding, bombRadius);
					Bombs.push_back(bomb);
					BombsLoc.push_back(bombLocation);
				}

				Value jPowerUp = jBlock["PowerUp"];
				if (jPowerUp.isNull()) {

				}
				else {
					string type = jPowerUp["$type"].asString();
					Location powerUPLocation(jPowerUp["Location"]["X"].asInt(), jPowerUp["Location"]["Y"].asInt());
					PowerUpsLoc.push_back(powerUPLocation);
				}
				Location blockLocation(jBlock["Location"]["X"].asInt(), jBlock["Location"]["Y"].asInt());
				bool exploding = jBlock["Exploding"].asBool();
				if (exploding) {
					ExplodingLoc.push_back(blockLocation);
				}
				rowBlock.push_back(entity);
			}
			Entities.push_back(rowBlock);
		}
	}

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

	

	char MyKey;
	int MapHeight = 21;
	int MapWidth = 21;
	double MapSeed;

	
	vector<Player> Players;
	vector<Bomb> Bombs;
	vector<vector<string>> Entities;

	vector<Location> EnemiesLoc;
	vector<Location> PowerUpsLoc;
	vector<Location> IndestructibleWallLoc;
	vector<Location> DestructibleWallsLoc;
	vector<Location> ExplodingLoc;
	vector<Location> BombsLoc;
};