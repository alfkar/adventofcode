
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;
#define UP -1
#define DOWN 1
#define RIGHT 1
#define LEFT -1
#define ZERO 0
#define GRIDSIZE 1000
#define STARTPOS 500

class coordinate {
    public:
        int count;
        char currentVisitor;
        map<int,int>visited;
};

class position {
    public:
        int id;
        int x;
        int y;
        int dirX;
        int dirY;
        position * parent;
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
    Head.dirX = 0;
    Head.dirY = 0;
    Head.id = 0;
    Head.x = STARTPOS;
    Head.y= STARTPOS;
    vector<position> Snake (9);
    Snake[0].parent = &Head;
    Snake[0].y = STARTPOS;
    Snake[0].x = STARTPOS;
    Snake[0].id = 0;
    Snake[0].dirX = 0;
    Snake[0].dirY = 0;
    // first, initialize a vector of ints with a given default val
    for(int i = 1; i<Snake.size(); i++){
        Snake[i].parent = &Snake[i-1];
        Snake[i].x = STARTPOS;
        Snake[i].y = STARTPOS; 
        Snake[i].id=i;
        Snake[i].dirX = 0;
        Snake[i].dirY = 0;
    }
    std::vector<coordinate> v(GRIDSIZE);
    std::vector<std::vector<coordinate>> grid(GRIDSIZE, v);

    for(int i = 0; i < input.size(); i++){
        char dir = input[i][0];
        int length = stoi(input[i].substr(2,input[i].size()));
        //cout<<"\n"<<input[i]<<"\n";
        switch (dir) {
            case 'U': 
                Head.dirY = UP;
                Head.dirX = ZERO;
                for(int k = 0; k < length; k++){
                    grid[Head.x][Head.y].currentVisitor = 0;
                    Head.y+=UP;
                    grid[Head.x][Head.y].currentVisitor = 'H';
                    for(int i = 0; i <Snake.size(); i++){   
                            int distanceY = abs(Snake[i].parent->y - Snake[i].y);
                            int distanceX = abs(Snake[i].parent->x - Snake[i].x);
                            int oldX = Snake[i].x;
                            int oldY = Snake[i].y;
                            if(distanceX > 1 || distanceY > 1){
                                grid[Snake[i].x][Snake[i].y].currentVisitor = 0;
                                if(distanceX > 1 && distanceY > 1){
                                    Snake[i].x += Snake[i].parent->dirX;
                                    Snake[i].y += Snake[i].parent->dirY; 
                                }
                                else if(distanceX > 1){
                                    Snake[i].x = Snake[i].parent->x - Snake[i].parent->dirX;
                                    Snake[i].y = Snake[i].parent->y; 
                                }
                                else if(distanceY > 1){
                                    Snake[i].x = Snake[i].parent->x;
                                    Snake[i].y = Snake[i].parent->y - Snake[i].parent->dirY; 
                                }
                                else{
                                Snake[i].x = Snake[i].parent->x - Snake[i].parent->dirX;
                                Snake[i].y = Snake[i].parent->y - Snake[i].parent->dirY;
                                }

                            }
                            Snake[i].dirX = Snake[i].x - oldX;
                            Snake[i].dirY = Snake[i].y - oldY;
                            int id = Snake[i].id;
                            grid[Snake[i].x][Snake[i].y].currentVisitor = id + 49;
                            if(!grid[Snake[i].x][Snake[i].y].visited.count(id)&& id == 8){
                                grid[Snake[i].x][Snake[i].y].count++;
                                grid[Snake[i].x][Snake[i].y].visited.insert({id, id});
                                T++;
                                
                                }
                        }
                        /*
                        for(int i=0; i<grid.size(); i++){
                        cout<<"\n";
                        for(int j = 0; j<grid.size(); j++){                          
                              if(j == STARTPOS && i ==STARTPOS){
                                    cout<<'s';
                                }
                            else if(grid[j][i].currentVisitor > 0 ){
                                cout<<grid[j][i].currentVisitor;
                                
                                }
                            else {
                                cout<<".";
                            }
                            }
                        }
                        cout<<"\n\n";
                        */
                        
                    }
                    
                break;
            case 'R':
                Head.dirY = ZERO;
                Head.dirX = RIGHT;
                for(int k = 0; k < length; k++){
                    grid[Head.x][Head.y].currentVisitor = 0;
                    Head.x+=RIGHT;
                    grid[Head.x][Head.y].currentVisitor = 'H';
                    for(int i = 0; i <Snake.size(); i++){
                            int distanceY = abs(Snake[i].parent->y - Snake[i].y);
                            int distanceX = abs(Snake[i].parent->x - Snake[i].x);
                            int oldX = Snake[i].x;
                            int oldY = Snake[i].y;
                            if(distanceX > 1 || distanceY > 1){
                                grid[Snake[i].x][Snake[i].y].currentVisitor = 0;
                                if(distanceX > 1 && distanceY > 1){
                                    Snake[i].x += Snake[i].parent->dirX;
                                    Snake[i].y += Snake[i].parent->dirY; 
                                }
                                else if(distanceX > 1){
                                    Snake[i].x = Snake[i].parent->x - Snake[i].parent->dirX;
                                    Snake[i].y = Snake[i].parent->y; 
                                }
                                else if(distanceY > 1){
                                    Snake[i].x = Snake[i].parent->x;
                                    Snake[i].y = Snake[i].parent->y - Snake[i].parent->dirY; 
                                }
                                else{
                                Snake[i].x = Snake[i].parent->x - Snake[i].parent->dirX;
                                Snake[i].y = Snake[i].parent->y - Snake[i].parent->dirY;
                                }

                            }
                            Snake[i].dirX = Snake[i].x - oldX;
                            Snake[i].dirY = Snake[i].y - oldY;
                            int id = Snake[i].id;
                            grid[Snake[i].x][Snake[i].y].currentVisitor = id + 49;
                            if(!grid[Snake[i].x][Snake[i].y].visited.count(id)&& id == 8){
                                grid[Snake[i].x][Snake[i].y].count++;
                                grid[Snake[i].x][Snake[i].y].visited.insert({id, id});
                                T++;
                                
                                }
                        }
                        /*
                        for(int i=0; i<grid.size(); i++){
                        cout<<"\n";
                        for(int j = 0; j<grid.size(); j++){                           
                             if(j == STARTPOS && i ==STARTPOS){
                                    cout<<'s';
                                }
                            else if(grid[j][i].currentVisitor > 0 ){
                                cout<<grid[j][i].currentVisitor;
                                
                                }
                            else {
                                cout<<".";
                            }
                        }
                        }
                        cout<<"\n\n";
                        */
                        
                        
                    }
                break;
            case 'D': 
                Head.dirY = DOWN;
                Head.dirX = ZERO;
                for(int k = 0; k < length; k++){
                    grid[Head.x][Head.y].currentVisitor = 0;
                    Head.y+=DOWN;
                    grid[Head.x][Head.y].currentVisitor = 'H';
                    for(int i = 0; i <Snake.size(); i++){
                            int distanceY = abs(Snake[i].parent->y - Snake[i].y);
                            int distanceX = abs(Snake[i].parent->x - Snake[i].x);
                            int oldX = Snake[i].x;
                            int oldY = Snake[i].y;
                            if(distanceX > 1 || distanceY > 1){
                                grid[Snake[i].x][Snake[i].y].currentVisitor = 0;
                                if(distanceX > 1 && distanceY > 1){
                                    Snake[i].x += Snake[i].parent->dirX;
                                    Snake[i].y += Snake[i].parent->dirY; 
                                }
                                else if(distanceX > 1){
                                    Snake[i].x = Snake[i].parent->x - Snake[i].parent->dirX;
                                    Snake[i].y = Snake[i].parent->y; 
                                }
                                else if(distanceY > 1){
                                    Snake[i].x = Snake[i].parent->x;
                                    Snake[i].y = Snake[i].parent->y - Snake[i].parent->dirY; 
                                }
                                else{
                                Snake[i].x = Snake[i].parent->x - Snake[i].parent->dirX;
                                Snake[i].y = Snake[i].parent->y - Snake[i].parent->dirY;
                                }

                            }
                            Snake[i].dirX = Snake[i].x - oldX;
                            Snake[i].dirY = Snake[i].y - oldY;
                            int id = Snake[i].id;
                            grid[Snake[i].x][Snake[i].y].currentVisitor = id + 49;
                            if(!grid[Snake[i].x][Snake[i].y].visited.count(id) && id == 8){
                                grid[Snake[i].x][Snake[i].y].count++;
                                grid[Snake[i].x][Snake[i].y].visited.insert({id, id});
                                T++;
                                }
                        }
                        /*
                        for(int i=0; i<grid.size(); i++){
                        cout<<"\n";
                        for(int j = 0; j<grid.size(); j++){                           
                             if(j == STARTPOS && i ==STARTPOS){
                                    cout<<'s';
                                }
                            else if(grid[j][i].currentVisitor > 0 ){
                                cout<<grid[j][i].currentVisitor;
                                
                                }
                            else {
                                cout<<".";
                            }
                            }
                        }
                        cout<<"\n\n";
                        */
                        
                    }
                break;
            case 'L': 
                Head.dirY = ZERO;
                Head.dirX = LEFT;
                for(int k = 0; k < length; k++){
                    grid[Head.x][Head.y].currentVisitor = 0;
                    Head.x+=LEFT;
                    grid[Head.x][Head.y].currentVisitor = 'H';
                    for(int i = 0; i <Snake.size(); i++){
                            int distanceY = abs(Snake[i].parent->y - Snake[i].y);
                            int distanceX = abs(Snake[i].parent->x - Snake[i].x);
                            int oldX = Snake[i].x;
                            int oldY = Snake[i].y;
                            if(distanceX > 1 || distanceY > 1){
                                grid[Snake[i].x][Snake[i].y].currentVisitor = 0;

                                if(distanceX > 1 && distanceY > 1){
                                    Snake[i].x += Snake[i].parent->dirX;
                                    Snake[i].y += Snake[i].parent->dirY; 
                                }

                                else if(distanceX > 1){
                                    Snake[i].x = Snake[i].parent->x - Snake[i].parent->dirX;
                                    Snake[i].y = Snake[i].parent->y; 
                                }
                                else if(distanceY > 1){
                                    Snake[i].x = Snake[i].parent->x;
                                    Snake[i].y = Snake[i].parent->y - Snake[i].parent->dirY; 
                                }
                                else{
                                Snake[i].x = Snake[i].parent->x - Snake[i].parent->dirX;
                                Snake[i].y = Snake[i].parent->y - Snake[i].parent->dirY;
                                }

                            }
                            Snake[i].dirX = Snake[i].x - oldX;
                            Snake[i].dirY = Snake[i].y - oldY;
                            int id = Snake[i].id;
                            grid[Snake[i].x][Snake[i].y].currentVisitor = id + 49;
                            if(!grid[Snake[i].x][Snake[i].y].visited.count(id) && id == 8){
                                grid[Snake[i].x][Snake[i].y].count++;
                                grid[Snake[i].x][Snake[i].y].visited.insert({id, id});
                                T++;
                                
                                }
                        }
                        /*
                        for(int i=0; i<grid.size(); i++){
                        cout<<"\n";
                        for(int j = 0; j<grid.size(); j++){
                            if(j == STARTPOS && i ==STARTPOS){
                                    cout<<'s';
                                }
                            else if(grid[j][i].currentVisitor > 0 ){
                                cout<<grid[j][i].currentVisitor;
                                
                                }
                            else {
                                cout<<".";
                            }
                            }
                        }
                        cout<<"\n\n";
                        */
                        
                    }
                break;
        }
        
    }
    /*
    for(int i=0; i<grid.size(); i++){
        cout<<"\n";
        for(int j = 0; j<grid.size(); j++){
            if(grid[j][i].count > 0 ){
                cout<<grid[j][i].count;
                }
            else {
                cout<<".";
            }
            }
        }
        */
        
        cout<<"\n\n\n";
        
        
    
    
    
  cout<<"\n"<<T;
}