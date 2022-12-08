
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

int charToInt (char c){
    return c%48;
}

int main()
{   
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }
    for(int i = 1; i<lines.size()-1; i++){
        for(int j = 1; j<lines.size()-1; j++){
            int curVal = charToInt(lines[i][j]);
            

        } 
    }


}