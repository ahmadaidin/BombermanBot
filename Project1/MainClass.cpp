#include <random>
#include "stdafx.h"
#include "Strategies\GreedyStrategy.hpp"

using namespace std;

//string readStateFile(string filePath);
 
void writeMoveFile(string filePath, int decision);

int _tmain(int argc, _TCHAR* argv[])
{
	string filePath = argv[2];

	cout << "Args: " << argc << std::endl;
	cout << "Player Key: " << argv[1] << std::endl;
	cout << "File Path: " << argv[2] << std::endl;

	char playerKey = argv[1][0];
	string inputFile = filePath + "/"+"state.json";
	string outputFile = filePath + "/" + "move.txt";
	GreedyStrategy greedy(playerKey, inputFile);
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
