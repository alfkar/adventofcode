
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int max(int v1, int v2){
    if(v1>v2){
        return v1;
    }
    return v2;
}



int splitter (string tickets){
    int intTickets [4];
    int stringValue = 0;
    int pointer = 0;
    for(int i = 0; i<tickets.size(); i++){
    if(tickets[i] != '-' && tickets[i] != ','){
            stringValue = stringValue*10 + tickets[i]%48;
        }
    if(tickets[i] == ',' || tickets[i] == '-' || i==tickets.size()-1){
    intTickets[pointer] = stringValue;
    //cout<<intTickets[pointer]<<"\n";
    stringValue = 0;
    pointer++;
    }
    }
    if(intTickets[0] <= intTickets[2] && intTickets[1] >= intTickets[3]){
        return 1;
    }
    if(intTickets[0] >= intTickets[2] && intTickets[1] <= intTickets[3]){
        return 1;
    }
   
    return 0;

}

int main()
{
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }
    
    int sum = 0;
    for(int i = 0; i<lines.size(); i++){
        sum += splitter(lines[i]);
    }
    cout<<sum;
}