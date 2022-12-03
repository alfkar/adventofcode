
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

string test = "";

int main()
{
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }
    int largestElf = 0;
    int elfSum = 0;
    for(int i = 0; i < lines.size(); i++){
        if(lines[i] == ""){
            if(elfSum > largestElf){
                largestElf=elfSum;
            }
            elfSum = 0;
        }
        if(lines[i] != ""){
        elfSum += stoi(lines[i]);
        }
    }
    cout << largestElf << endl;

    return 0;
}