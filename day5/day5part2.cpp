
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <list>
using namespace std;


int main()
{   
    vector<stack<char> > stacks(9);
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }
    vector<int> data((lines.size()-10)*3);
    for(int i = 7; i>=0; i--){
        string line = lines[i];
        int stackIndex = 0;
        
        for(int i = 1; i<line.size(); i+=4){
            if(line[i] != ' '){
            stacks[stackIndex].push(line[i]);

            

            }
            stackIndex++;

        }
        cout<<"\n";
        
    }
    int dataindex = 0;
    for(int i = 10; i<lines.size(); i++){
        for(int j = 0; j<lines[i].size(); j++){
            int converted = 0;
            string line = lines[i];
            while (line[j] > 47 && line[j] < 58){
                converted = converted*10 + line[j]%48;
                j++;
                if(line[j] < 47 || line[j] > 58){
                data[dataindex] = converted;
                dataindex++;
                }
            }
            

        }

    }
    for(int i = 0; i<data.size(); i+=3){
        int movements = data[i];
        int movingStack = data[i+1]-1;
        int receivingStack = data[i+2]-1; 
        stack <char> mockStack;

        for(int j = 0; j < movements; j++){
            if(!stacks[movingStack].empty()){
            char moving = stacks[movingStack].top();
            mockStack.push(moving);
            stacks[movingStack].pop();
            }
            else break;
        }
        for(int j = 0; j < movements; j++){
            if(!mockStack.empty()){
            char moving = mockStack.top();
            stacks[receivingStack].push(moving);
            mockStack.pop();
            }
            else break;
        }
    }
    for(int i = 0; i<stacks.size(); i++){
        if(!stacks[i].empty()){
            cout<<stacks[i].top();
        }
    }

}