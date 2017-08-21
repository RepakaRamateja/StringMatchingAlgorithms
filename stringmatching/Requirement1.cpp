#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include"kruthmorris.h"
#include"Windowsstopwatch.h"
#include"boyer-moore.h"
#include"Rabin-Karp.h"
#include"AhoChorsick.h"
#include"suffixtree.h"


//functions which splits the given line using the delimiter space
void bsplit(const std::string &s, std::string sep, std::vector<std::string> &read)
{

	char* cstr = const_cast<char*>(s.c_str());
	char* current;

	current = strtok(cstr, sep.c_str());
	while (current != NULL) {
		read.push_back(current);
		current = strtok(NULL, sep.c_str());
	}
}

//#ifdef req1
/*
int main()
{

std::cout << "\nreading the given input file for search\n";

std::ifstream infile("../T.txt");

if (infile)
std::cout << "\nable to read the  given text file\n";
else
std::cout << "\nnot able to read given  the file\n";

std::cout << "\nreading the given patterns\n";

std::ifstream infile2("../P.txt");

if (infile2)
std::cout << "\n able to read the patterns file\n";
else
std::cout << "\n not able to read the patterns file\n";


//std::cout << "\n---------------------start of morris algorithm testcase------------------------\n";

std::string filecontents;
while (std::getline(infile, line))
{
filecontents = filecontents + line;
filecontents = filecontents + "\n";
}

std::vector<std::string> read;

std::string line;
while (std::getline(infile2,line))
{
bsplit(line, "\n", read);
}

/*
morris obj;

for (size_t i = 0; i < read.size(); i++)
{
morris obj;
WindowsStopwatch watch;
watch.start();
if (obj.KMP(read[i], filecontents))
{
std::cout << "\nfound pattern        "<<read[i];
}
watch.stop();
std::cout << "\ntime taken to search     ";
std::cout << watch.getTime();
}
std::cout << "\n";


std::cout << "\n----------------------------end of morris algorithm test case-------------------\n";


std::cout << "\n --------------start of boyes moore test case---------------------\n";
std::cout << "\n";

char *filecontent;
filecontent = (char *)malloc(filecontents.size() + 1);
memcpy(filecontent, filecontents.c_str(), filecontents.size() + 1);

for (size_t i = 0; i < read.size(); i++)
{
char *pattern;
pattern = (char *)malloc(read[i].size() + 1);
memcpy(pattern, read[i].c_str(),read[i].size() + 1);
boyermoore boyer;
WindowsStopwatch watch;
watch.start();
boyer.search(filecontent, pattern);
watch.stop();
std::cout << "\n the time taken to find that pattern "<<read[i]<<" "<< watch.getTime()<<std::endl;
std::cout << "\n";

}

std::cout << "\n-------------- end of boyes moore test case ----------------------------\n";
std::cout << "\n";

std::cout << "\n------------ start of rabin karp algorithm--------------------\n";
std::cout << "\n";

for (size_t i = 0; i < read.size(); i++)
{
char *pattern;
pattern = (char *)malloc(read[i].size() + 1);
memcpy(pattern, read[i].c_str(), read[i].size() + 1);
boyermoore boyer;
int q = 101;
WindowsStopwatch watch;
watch.start();
rabin obj;
obj.search(pattern, filecontent, q);
watch.stop();
std::cout << "\n the time taken to find that pattern " << read[i] << " " << watch.getTime() << std::endl;
std::cout << "\n";
}

std::cout << "\n--------------end of rabin karp algorithm----------------------\n";

std::cout << "\n";*/

//std::cout << "\n---------- start of AhoChorasick algorithm-------------------\n";


/*

std::vector<std::string> read2;
read2.push_back("he");
int k = read2.size();


searchWords(read2, k,filecontents);

*/
// working code for suffix tree implementaion

/*
ifstream ifs1("../T.txt");
string text((istreambuf_iterator<char>(ifs1)), (istreambuf_iterator<char>()));
ifs1.close();

std::cout << "\nbefore suffix tree\n";

buildSuffixTree(filecontents);
checkForSubString("CACGGTCATGAGGGC");
*/



//code for aho corasick algorithm
/*
ifstream ifs1("../T.txt");
string text((istreambuf_iterator<char>(ifs1)), (istreambuf_iterator<char>()));
ifs1.close();*/
/*
string arr[] = { "he", "she", "hers", "his" };
string text = "ahishers";
int k = sizeof(arr) / sizeof(arr[0]);

searchWords(arr, k, text);

return 0;*/
//}
//#endif