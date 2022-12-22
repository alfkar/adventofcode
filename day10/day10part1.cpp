
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
void updateSprite(string * sprite, int position){
    for(char pixel: * sprite){
        pixel = '#';
    }

}

int main()
{   
    std::string sprite = "###.....................................";
    std::string CRT; 
    int cycle = 0;
    int X = 1;
    int signalStrengthSum = 0;
    vector<string> input;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        input.push_back(line);
    }
    for(string line: input){
        string operation = line.substr(0,4);
            
        
        //cout<<"\n"<<operation;
        if(operation == "addx"){
            //cout<<"\n \n \nSprite: "<<sprite<<"\n";
            int value = stoi(line.substr(4, line.size()));
            
            
            if(sprite[cycle%40] == '#'){
            CRT.append("#");
            }
            else{
            CRT.append(".");
            }
            cycle++;
           // cout<<"Cycle: "<<cycle<<" \n";
                   
            if(sprite[cycle%40 ] == '#'){
            CRT.append("#");
            }
            else{
            CRT.append(".");
            }
            cycle++;  
            //cout<<"\nCycle: "<<cycle<<" \n";
            
            sprite[(X-1+40)%40]='.';
            sprite[(X+40)%40]='.';
            sprite[(X+1+40)%40]='.';
            
            X += value;

            sprite[(X-1+40)%40]='#';
            sprite[(X+40)%40]='#';
            sprite[(X+1+40)%40]='#';
            
        }
        else{
            cycle++;
            if(sprite[cycle%40] == '#'){
            CRT.append("#");
            }
            else{
            CRT.append(".");
            }
            //cout<<"\n";
        }
    }
    //cout<<CRT.size();
    
    for(int i = 0; i < CRT.size(); i++){

        if(i%40 == 0 && i!=0){
            cout<<"\n";
        }
        cout<<CRT[i];
    }
    
    

}