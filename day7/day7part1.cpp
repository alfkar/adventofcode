
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

#define signalLength 4

/*
- / (dir)
  - a (dir)
    - e (dir)
      - i (file, size=584)
    - f (file, size=29116)
    - g (file, size=2557)
    - h.lst (file, size=62596)
  - b.txt (file, size=14848514)
  - c.dat (file, size=8504156)
  - d (dir)
    - j (file, size=4060174)
    - d.log (file, size=8033020)
    - d.ext (file, size=5626152)
    - k (file, size=7214296)
*/
struct node{
    int mySize;
    string myName;
    struct node *parent;
    vector<node> children;
};

struct node *newNode(int size, string name){
    struct node *temp = new node;
    temp->mySize = size;
    temp->myName = name;
    temp->parent = NULL;
    return temp;
}

int readInt (string input){
    int i = 0;
    int result = 0;
    if(input[0]=='d'){
        return 0;
    }
    while(input[i] != ' '){
        result = result*10+input[i]%48;
        i++;
    }
    return result;
}
string readName (string input){
    if(input[0]=='d'){
        //cout << input.substr(4,input.length());
        return input.substr(4,input.length());
    }
    for(int i = 0; i<input.length(); i++){
        if(input[i] == ' '){
            //cout<<input.substr(i, input.length());
            return input.substr(i, input.length());
        }
    }
}

int main()
{   
    vector<string> lines;
    ifstream contents("input2.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }
    node *parentNode = newNode(0, "/");
    for(int i = 0; i<lines.size(); i++){
        string line = lines[i];
        if(line == "$ ls"){
            i++;
            line = lines[i];
            while(line[2] !='c' && line[3] !='d' && i<lines.size()){
                //cout<<line<<"\n";
                node *child = newNode(readInt(line), readName(line));
                child->parent = parentNode;
                parentNode->children.push_back(*child);
                i++;
                line = lines[i];
               
            }
        }
        string directory;
        if(line[2] == 'c' && line[3]== 'd'){
        directory = line.substr(5, line.size());
        }
        if(directory == ".." && parentNode -> myName != "/"){
            parentNode = parentNode->parent;
        }
        else{
            for(int j = 0; j<parentNode->children.size(); j++){
                if(directory == parentNode->children[j].myName){
                  *parentNode = parentNode->children[j];
                }
            }
        }
    }
    /*
    while(parentNode->myName != "/"){
        parentNode = parentNode -> parent;
    }
    */
    //cout<<parentNode->myName;
    for(int i = 0; i<parentNode->children.size(); i++){
    cout<<parentNode->children[i].myName;
    }
    

}