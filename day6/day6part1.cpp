
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

#define signalLength 4 

bool containsDuplicate(string signal){
    map<int, char>signalMap;
    for(char s: signal){
        if(!signalMap.count(s%32)){
        signalMap[s%32]=s;
        }
        else{
            return true;
        }
    }
    return false;
}

int main()
{   
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }

    for(int i = 0; i < lines[0].size()-signalLength; i++){
        string signal = lines[0].substr(i,signalLength);
        if(!containsDuplicate(signal)){
            cout<<i+signalLength;
            break;
        }
        

    }

}