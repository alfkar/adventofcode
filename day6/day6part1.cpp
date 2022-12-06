
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <list>
using namespace std;


bool isDuplicate(int first, int second, int third, int fourth){
    if(first!=second && first!=third && first!=fourth && second!=third && second !=fourth&&third != fourth){
        return true;
        }
    return false;
} 



int main()
{   
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }
    vector<char> arr(4);
    for(int i = 0; i < lines.size()-4; i++){
        
        char first  = lines[0][i];
        char second = lines[0][i+1];
        char third  = lines[0][i+2];
        char fourth = lines[0][i+3];
        if(isDuplicate(first, second, third, fourth)){
            cout<<i+4;
            break;
        }
    }

}