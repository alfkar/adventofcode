
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
    int currentLeader = 0;

    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }
    for(int i = 1; i<lines.size()-1; i++){
        cout<<"\n";
        for(int j = 1; j<lines[i].size()-1; j++){
            //cout<<lines[i][j];
            int left = 0;
            int right = 0;
            int up = 0;
            int down = 0;
            int contestant = 0;
            int curVal = charToInt(lines[i][j]);
            bool visible = true;
            for(int k = j-1; k>=0; k--){
                int tmpTree = charToInt(lines[i][k]);
                if(curVal > tmpTree){
                    left++;
                }
                else{
                    left++;
                    break;
                }
            }
            for(int k = j+1; k<lines[i].size(); k++){
                int tmpTree = charToInt(lines[i][k]);
                //cout<<tmpTree;
                if(curVal > tmpTree){
                    right++;
                }
                else{
                    right++;
                    break;
                }
            }
            
            for(int k = i-1; k>=0; k--){
                int tmpTree = charToInt(lines[k][j]);
                if(curVal > tmpTree){
                    up++;
                }
                else{
                    up++;
                    break;
                }
            }
            for(int k = i+1; k<lines.size(); k++){
                int tmpTree = charToInt(lines[k][j]);
                if(curVal > tmpTree){
                    down ++;
                }
                else{
                    down ++;
                    break;
                }
            }
            cout<<up<<"*"<<left<<"*"<<down<<"*"<<right<<"  ";
            contestant = left*right*up*down;
            if(currentLeader < contestant){
                currentLeader = contestant;
            }
            

        } 
    }
    cout<<"\n\nwinner: "<<currentLeader;

}