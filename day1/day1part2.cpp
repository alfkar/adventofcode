
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

string test = "";

int main()
{
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }
    int GoldElf = 0;
    int SilverElf = 0;
    int BronzeElf = 0;
    int elfSum = 0;
    for(int i = 0; i < lines.size(); i++){
        if(lines[i] == ""){
            if(elfSum > GoldElf){
                BronzeElf=SilverElf;
                SilverElf=GoldElf;
                GoldElf=elfSum;
            }
            else if(elfSum > SilverElf){
                BronzeElf=SilverElf;
                SilverElf=elfSum;
            }
            else if (elfSum > BronzeElf){
                BronzeElf=elfSum;
            }
            elfSum = 0;
        }
        if(lines[i] != ""){
        elfSum += stoi(lines[i]);
        }
    }
    int total = GoldElf + SilverElf + BronzeElf;
    cout << total << endl;

    return 0;
}