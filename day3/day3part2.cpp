
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


int sumRuckSack(string elfOne, string elfTwo, string elfThree){
    int badge = 0;
    for(int i = 0; i<elfOne.size(); i++){
        for(int j = 0; j < elfTwo.size(); j++){
            for(int k = 0; k < elfThree.size(); k++){
                    if(elfOne[i] == elfTwo[j] && elfOne[i] == elfThree[k]){
                        return convertAscii(elfOne[i]);
                    }
                 }            
            }
        }
        return badge;
    }

int main()
{
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }
    int totalSum = 0;
    for(int i = 0; i<lines.size(); i+=3){
        totalSum += sumRuckSack(lines[i],lines[i+1],lines[i+2]); 

    }
    cout<<totalSum;

    return 0;
}