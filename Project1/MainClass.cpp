#include <random>
#include "stdafx.h"
#include "json.hpp"

using namespace std;

int main() {
	string filePath = aa;
	cout << "Reading state file " << filePath + "/" + "state.json" << std::endl;

	return 0;
}
/*void readStateFile(string filePath);
void writeMoveFile(string filePath);

int _tmain(int argc, _TCHAR* argv[])
{
	string filePath = argv[2];

	cout << "Args: " << argc << std::endl;
	cout << "Player Key: " << argv[1] << std::endl;
	cout << "File Path: " << argv[2] << std::endl;

	readStateFile(filePath);
	writeMoveFile(filePath);
	return 0;
}

void readStateFile(string filePath)
{
	cout << "Reading state file " << filePath + "/" + "state.json" << std::endl;
	cout << "writing state file " << filePath + "/" + "state.txt" << std::endl;
	string fileContent;
	string line;
	ifstream myfile(filePath + "/" + "state.json");

	ofstream outfile(filePath + "/" + "state.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			fileContent += line += "\n";

			if (outfile.is_open()) {
				outfile << fileContent << std::endl;
				outfile.close();
			}
		}
		myfile.close();
	}
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

