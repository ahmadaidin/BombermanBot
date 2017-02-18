#pragma once

#include "../header.h"
#include "../Map/Block.hpp"

class Map {
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