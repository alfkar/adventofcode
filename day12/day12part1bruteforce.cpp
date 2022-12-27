
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <math.h>
//#define backOK 0
#define backOK 140

using namespace std;
int currentShortestPath = 1000000000;

int bruteForce (vector<string> input, char Goal, vector<vector <bool>> grid, int x, int y, int pathLength){
    grid[y][x] = true;
    //cout<<input[y][x]<<"\n";
    char currentPos = input[y][x];
    if(currentPos < 'a' ){
        currentPos = 'z';
    }

    if(input[y][x]==Goal){
        if(pathLength < currentShortestPath){
         currentShortestPath=pathLength;
         cout<<currentShortestPath<<"\n";
        }
        /*
        for(int i = 0; i<grid.size(); i++){
            cout<<"\n";
            for(int j = 0; j<grid[0].size(); j++){
                cout<<grid[i][j];
                
            }

        }
        cout<<"\n\n\n";
        */
        return 1;
    }
    if(x<grid[0].size()-1){
        char nextPos = input[y][x+1]-1;
        if(nextPos == 'E'-1){
            nextPos = 'z'-1;
        }
        if(nextPos<=currentPos && !grid[y][x+1]){
        
            bruteForce(input, Goal, grid, x+1, y, pathLength + 1);
        }
    }
    
    if(x<grid[0].size()-1){
        char nextPos = input[y][x+1];
        if(nextPos == 'E'-1){
            nextPos = 'z'-1;
        }
        if(!grid[y][x+1] && (nextPos==currentPos || nextPos-1==currentPos)){
            bruteForce(input, Goal, grid, x+1, y, pathLength + 1);
        }
    }
    if(y<grid.size()-1){
        char nextPos = input[y+1][x];
        if(nextPos == 'E'-1){
            nextPos = 'z'-1;
        }
        if((nextPos==currentPos || nextPos-1==currentPos) && !grid[y+1][x]){
            bruteForce(input, Goal, grid, x, y+1,pathLength + 1);
        }
    } 

    if(y>0){
       char nextPos = input[y-1][x];
        if(nextPos == 'E'-1){
            nextPos = 'z'-1;
        }
        if((nextPos==currentPos || nextPos-1==currentPos)&& !grid[y-1][x]){
            bruteForce(input, Goal, grid, x, y-1,pathLength +1);
        }
    }
    if(x>backOK){
        char nextPos = input[y][x-1];
        if(nextPos == 'E'-1){
            nextPos = 'z'-1;
        }
        if((nextPos==currentPos || nextPos-1==currentPos)&& !grid[y][x-1]){
            bruteForce(input, Goal, grid, x-1, y,pathLength + 1);
        }
    
    }
    return 0;

}


int main()
{   
    vector<string> input;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        input.push_back(line);
    }
    vector<bool> rows(input[0].size(),false);
    vector<vector <bool>> grid (input.size(),rows);
    bruteForce(input, 'E', grid, 0, 0, 0);
    cout<<currentShortestPath;
}