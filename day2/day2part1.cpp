#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


#define DRAW 2
#define LOSE 1 
#define WIN 0

int gameResult(char opponent, char player){
    int choiceValue = player % 87;
    int result = (player - opponent) % 3;
    switch(result) {
        case WIN:
            return 6 + choiceValue;
            break;
        case DRAW:
            return 2 + choiceValue;
            break;
        case LOSE:
            return 0 + choiceValue;
            break;
        default: 
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
      sum += gameResult(lines[i][0],lines[i][2]);
    }
    cout<<sum;
    return 0;
}