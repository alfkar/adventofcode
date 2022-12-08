
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

int main()
{   
    int nOfVisible = 0;
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }
    for(int i = 1; i<lines.size()-1; i++){
        //cout<<"\n";
        for(int j = 1; j<lines[i].size()-1; j++){
            //cout<<lines[i][j];
            int curVal = charToInt(lines[i][j]);
            bool visible = true;
            for(int k = 0; k<j; k++){
                int tmpTree = charToInt(lines[i][k]);
                if(curVal > tmpTree){
                    visible = true;
                }
                else{
                    
                    visible = false;
                    break;
                }
            }
            if(visible){
                nOfVisible++;
                continue;
            }
            for(int k = j+1; k<lines[i].size(); k++){
                int tmpTree = charToInt(lines[i][k]);
                //cout<<tmpTree;
                if(curVal > tmpTree){
                    visible = true;
                }
                else{
                    visible = false;
                    break;
                }
            }
            //cout<<"\n";

            if(visible){
                nOfVisible++;
                continue;
            }
            for(int k = 0; k<i; k++){
                int tmpTree = charToInt(lines[k][j]);
                if(curVal > tmpTree){
                    visible = true;
                }
                else{
                    visible = false;
                    break;
                }
            }
            if(visible){
                nOfVisible++;
                continue;
            }
            for(int k = i+1; k<lines.size(); k++){
                int tmpTree = charToInt(lines[k][j]);
                if(curVal > tmpTree){
                    visible = true;
                }
                else{
                    visible = false;
                    break;
                }
            }
             if(visible){
                nOfVisible++;
                continue;
            }
            

        } 
    }
    nOfVisible+= 2*lines.size() - 4;
    nOfVisible+= 2*lines[0].size();
    //cout<<nOfVisible;

}