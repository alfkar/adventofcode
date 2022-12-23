
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <math.h>

using namespace std;

class Monkey{
    public:
        int id;
        vector <int> sItems;
        char op;
        int opValue;
        int divBy;
        int throwTrue;
        int throwFalse;
        int inspectedItems = 0;
};      

int main()
{   
    vector<string> input;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        input.push_back(line);
    }
    vector <Monkey> monkeys;
   
    int id = 0;
    for(int i = 0; i<input.size(); i+=7){
        Monkey currentMonkey;
        currentMonkey.id=id;
        id++;
        int item = 0;
        string line1 = input[i+1].substr(18,input[i+1].size());
        for(int j = 0; j<line1.size(); j++ ){
            if(j % 4 == 2){
                currentMonkey.sItems.push_back(item);
                item = 0;
                j++;
                continue;
            }
            item = item*10 + line1[j]%48; 

        }
        currentMonkey.sItems.push_back(item);
        string line2 = input[i+2].substr(23,input[i+2].size());
        currentMonkey.op = line2[0];
        int opValue = 0;
        for(int j = 2; j<line2.size(); j++){
            if(line2[j] == 'o'){
                opValue = 0;
                break;
            }
            opValue = opValue*10 + line2[j]%48;
        }
        currentMonkey.opValue = opValue;
        int div = 0;
        string line3 = input[i+3].substr(21,input[i+3].size());
        for(int j = 0; j<line3.size(); j++){
            div = div*10 + line3[j]%48;
        }
        currentMonkey.divBy = div;
        currentMonkey.throwTrue = input[i+4][input[i+4].size()-1] % 48;
        currentMonkey.throwFalse = input[i+5][input[i+5].size()-1] % 48;
        monkeys.push_back(currentMonkey);
    }
    for(int i = 0; i<20; i++){
        for(Monkey currentMonkey: monkeys){
            while(currentMonkey.sItems.size() > 0){
                int worryNew = currentMonkey.sItems[0];
                int opValue = currentMonkey.opValue;
                if(opValue == 0){
                    opValue = worryNew;
                }
                if(currentMonkey.op == '+'){
                worryNew = worryNew + opValue;
                }
                else{
                worryNew = worryNew * opValue;
                }
                worryNew = worryNew/3; 
                if(worryNew % currentMonkey.divBy == 0){
                    monkeys[currentMonkey.throwTrue].sItems.push_back(worryNew);
                }
                else{
                    monkeys[currentMonkey.throwFalse].sItems.push_back(worryNew);
                }
                currentMonkey.sItems.erase(currentMonkey.sItems.begin());
                currentMonkey.inspectedItems += 1;

            }
            monkeys[currentMonkey.id] = currentMonkey;
        

        }
        
    }
    int winner = 0;
    int second = 0;
    for(Monkey M: monkeys){
        cout<<M.inspectedItems<<"\n";
        if(winner < M.inspectedItems){
            second = winner;
            winner = M.inspectedItems;
            continue;
        }
        if(second < M.inspectedItems){
            second = M.inspectedItems;
        }

    }
    int tot = winner * second;
    cout<<tot;


    

}