
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


int main()
{
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }

    return 0;
}