#include <random>
#include "stdafx.h"
#include "json.hpp"

using namespace std;
using namespace nlohmann;

string readStateFile(string filePath);
void writeMoveFile(string filePath);

int main() {
	string filePath = "roundInfo.json";
//	cout << "Reading state file state.json" << std::endl;
	//string jsonString = readStateFile(filePath);
	json jsonString = readStateFile(filePath);
//	auto j = R"("+jsonString+")"_json;
	cout << jsonString["MapSeed"]<< endl;
	//cout << jsonString["RegisteredPlayerEntities"]<< endl;
	return 0;
}

string readStateFile(string filePath)
{
	cout << "Reading state file " << filePath  << std::endl;
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
/*int _tmain(int argc, _TCHAR* argv[])
{
	string filePath = argv[2];

	cout << "Args: " << argc << std::endl;
	cout << "Player Key: " << argv[1] << std::endl;
	cout << "File Path: " << argv[2] << std::endl;

	readStateFile(filePath);
	writeMoveFile(filePath);
	return 0;
}*/

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

