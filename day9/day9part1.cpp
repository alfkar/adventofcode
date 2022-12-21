
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;


class position {
    public:
        int x = 0;
        int y = 0;
        map<int, bool> visited;

    



};

int readInt (string s ){
    int result = 0;
    for(int i = 2; i<s.size(); i++){
        result += result*10 + s[i]%48;
    }
    return result;
} 



int main()
{   
    int T = 0;
    vector<string> input;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        input.push_back(line);
    }
    position Head;
    position Tail;
    // first, initialize a vector of ints with a given default value
    std::vector<bool> v(1000);
    std::vector<std::vector<bool>> grid(1000, v);
    Head.y = grid.size()/2;
    Tail.y = grid.size()/2;
    Head.x = grid.size()/2;
    Tail.x = grid.size()/2;
    for(int i = 0; i <input.size(); i++){
        char dir = input[i][0];
        int length = stoi(input[i].substr(2,input[i].size())); 
       // cout<<length<<"\n";
       // std::cout<<"X: "<<Tail.x<<" Y: "<<Tail.y<<"\n";
        switch (dir) {
            case 'U': 
                for(int i = 0; i<length; i++){
                    Head.y--;
                    if(!grid[Tail.x][Tail.y]){
                        grid[Tail.x][Tail.y] = true;
                        T++;
                    }
                    int distanceY = abs(Head.y - Tail.y);
                    if(distanceY > 1){
                        Tail.x = Head.x;
                        Tail.y = Head.y+1;
                    }
                    if(!grid[Tail.x][Tail.y]){
                        grid[Tail.x][Tail.y] = true;
                        T++;
                    }
                }
            //cout<<"U: "<<T<<"\n";
                break;
            case 'R':
            
            for(int i = 0; i<length; i++){
                    Head.x++;
                    if(!grid[Tail.x][Tail.y]){
                        grid[Tail.x][Tail.y] = true;
                        T++;
                    }                
                    int distanceX = abs(Head.x - Tail.x);
                    if(distanceX > 1){
                        Tail.x = Head.x-1;
                        Tail.y = Head.y;
                    }
                    if(!grid[Tail.x][Tail.y]){
                        grid[Tail.x][Tail.y] = true;
                        T++;
                    }


                }
                //cout<<"R: "<<T<<"\n";
                break;

            case 'D': 
                for(int i = 0; i<length; i++){
                    Head.y++;
                    if(!grid[Tail.x][Tail.y]){
                        grid[Tail.x][Tail.y] = true;
                        T++;
                        }
                    int distanceY = abs(Head.y - Tail.y);
                    if( distanceY > 1){
                        Tail.x = Head.x;
                        Tail.y = Head.y-1;

                    }
                    if(!grid[Tail.x][Tail.y]){
                        grid[Tail.x][Tail.y] = true;
                        T++;
                    }

                }
                //cout<<"D: "<<T<<"\n";
                break;
            case 'L': 
              
                for(int i = 0; i<length; i++){
                    Head.x--;
                    if(!grid[Tail.x][Tail.y]){
                       grid[Tail.x][Tail.y] = true;
                        T++;
                    }                
                    int distanceX = abs(Head.x - Tail.x);
                    if(distanceX > 1){
                        Tail.x = Head.x+1;
                        Tail.y = Head.y;
                    }
                    /*
                    else if(Tail.y  == Head.y && distanceX > 1){ 
                        Tail.x--;
                    }
                    */
                   if(!grid[Tail.x][Tail.y]){
                        grid[Tail.x][Tail.y] = true;
                        T++;
                    }


                }

                //cout<<"L: "<<T<<"\n";
                break;
        }

        
    }
    /*
    for(int i=0; i<grid.size(); i++){
        cout<<"\n";
        for(int j = 0; j<grid.size(); j++){
            cout<<grid[j][i];
        }
    }
    */
    
  cout<<"\n"<<T;
}