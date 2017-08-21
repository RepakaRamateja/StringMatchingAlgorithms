// TestAhoCorasik.cpp : Defines the entry point for the console application.
//



#include <stdio.h>

#include "Suffixtree.h"
#include<fstream>
#include<string>
#include<iostream>
#include<vector>



using namespace std;

void bfsplit(const std::string &s, std::string sep, std::vector<std::string> &read)
{

	char* cstr = const_cast<char*>(s.c_str());
	char* current;

	current = strtok(cstr, sep.c_str());
	while (current != NULL) {
		read.push_back(current);
		current = strtok(NULL, sep.c_str());
	}
}

int main(int argc, char* argv[])
{

	ifstream ifs1("../T.txt");
	string text((istreambuf_iterator<char>(ifs1)), (istreambuf_iterator<char>()));
	ifs1.close();



	std::ifstream infile2("../P.txt");
	std::vector<std::string> read;
	std::string line;



	while (std::getline(infile2, line))
	{
		bfsplit(line, "\n", read);
	}

	CSuffixTrie aTree;
	/*
	for (int i = 0; i < read.size(); i++)
	{
		std::string str = read[i];
		std::wstring ws;
		ws.assign(str.begin(), str.end());
		aTree.AddString(ws);
	}*/

	wstring wtext(text.begin(), text.end());

	aTree.AddString(wtext);
	
	aTree.BuildTreeIndex();
	CSuffixTrie::_DataFound aData;
	CSuffixTrie::_DataFound aDatax;
	CSuffixTrie::DataFoundVector aDataFound;

	wstring ptext(read[0].begin(),read[0].end());
	
	aDatax = aTree.SearchAhoCorasik(ptext);

	printf("%i",aDatax.iFoundPosition);

	for (int iCount = 0;
		iCount<aDataFound.size();
		++iCount)
		printf("%S %i\n", aDataFound[iCount].sDataFound.c_str(), aDataFound[iCount].iFoundPosition);

	return 0;
}
