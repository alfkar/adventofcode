
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <list>
using namespace std;



int main()
{   
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }
    
    for(int i = 0; i < lines[0].size()-14; i++){
        bool signal = false;

        for(int j = i; j < i+14; j++){
            for(int k = j+1; k<i+14; k++){
                if(lines[0][j] == lines[0][k]){
                    signal = true;
                }
            }

        }
        if(!signal){
            cout<<i+14<<"\n";
            break;
        }

    }

}