
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <math.h>
//#define backOK 0
#define row 179
#define col 41

using namespace std;

typedef pair<int, int> Pair;
typedef pair<double, pair<int, int> > pPair;
struct cell{
    // 0 <= parent_i <= row-1 , 0 <= parent_j <= col -1;
    int parent_i, parent_j;
    //f = g + h
    double f, g, h;
};

bool visited (vector<vector<bool>>, int row, int col){


}



int main()
{   
    vector<string> input;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        input.push_back(line);
    }
    vector<bool> rows(input[0].size(),false);
    vector<vector <bool>> grid(input.size(),rows);
    
}