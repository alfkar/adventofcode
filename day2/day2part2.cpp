#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


#define WIN 2
#define DRAW 1 
#define LOSE 0

int gameResult(char opponent, char result){
    int choiceValue = result % 88;
    switch(choiceValue) {
        case WIN:
            return 6 + (opponent-1) % 3 + 1;
        case DRAW:
            return 3 + opponent % 64;
        case LOSE:
            return opponent % 3 + 1;
            break;
        }
    }


int main()
{
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }
    int sum = 0;
    for(int i = 0; i < lines.size(); i++){
      cout<<gameResult(lines[i][0],lines[i][2])<<"\n";
      sum += gameResult(lines[i][0],lines[i][2]);
    }
    cout<<sum;
    return 0;
}