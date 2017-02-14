#include "Node.hpp"
#include "../Map/Map.hpp"

class NodeMap{
public:
	NodeMap() {

	}

	NodeMap(Map map, char playerKey) {
		this->map = map;
		this->playerKey = playerKey;
		nodes = vector<Node>();
		for (int y = 1; y < map.getHeight(); y++)
		{
			for (int x = 1; x < map.getWidth; x++)
			{
				Block block = map.getBlock(x, y);
				if (block.getEntity().getType() == INDES_WALL)
					continue;

				nodes.push_back(block);
			}
		}
		//playerNode = nodes.front();
	}

private:
	char playerKey;
	Map map;
	vector<Node> nodes;
	Node playerNode;
};