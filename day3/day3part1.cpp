
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


int convertAscii (char number){
    if(number>90){
        return (number % 32);
    }
    else if (number>64){
    return (number % 32) + 26;
    }
    else return 0;
}
bool noDup(char array [], char item, int size){
    for(int i = 0; i < size; i++){
        if(item == array[i]){
            return false;
        }
    }
    return true;
}


int sumRuckSack(string ruckSack){
    int  componentSize = ruckSack.size()/2;
    char sumPriority[componentSize] = {0};
    int  sumPointer = 0;
    for(int i = 0; i<componentSize; i++){
        for(int j = componentSize; j < 2*componentSize; j++){
            if( ruckSack[i] == ruckSack[j] && noDup(sumPriority, ruckSack[i], componentSize)){
                sumPriority[sumPointer] = ruckSack[i];
                sumPointer++;            
            }
        }
    }
    int sum = 0;
    for(int i = 0; i<componentSize-1; i++){
        sum += convertAscii(sumPriority[i]);
    }
    return sum;
}

int main()
{
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }
    int totalSum = 0;
    for(int i = 0; i<lines.size(); i++){
        totalSum += sumRuckSack(lines[i]); 

    }
    cout<<totalSum;

    return 0;
}