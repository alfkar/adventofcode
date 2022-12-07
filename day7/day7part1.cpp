
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


class Node{
    public: 
        int myValue;
        string myName;
        Node *parent;
        vector<Node> children;
};



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
            return input.substr(i+1, input.length());
        }
    }
}
void printTree(Node * Current, string level){
    if(Current->myName == "/"){
        cout<<Current->myName<<"\n";
    }
    level.append(" ");
    if(Current -> children.size() == 0){
        return;
    }
    else{
        for(int i = 0; i < Current->children.size(); i++){
        cout<<level<<Current->children[i].myName<<"\n";
        Node * child = &Current->children[i];
        printTree(child,level);
        }
    }
}

int main()
{   
    vector<string> lines;
    ifstream contents("input.txt");
    for (string line; getline(contents, line);){
        lines.push_back(line);
    }
    Node firstNode;
    firstNode.myName = "/";
    firstNode.myValue = 0;
    Node *currentNode = &firstNode;
    
    for(int i = 0; i<lines.size(); i++){
        string line = lines[i];
        if(line == "$ ls"){
            i++;
            line = lines[i];
            while(line[2] !='c' && line[3] !='d' && i<lines.size()){
                //cout<<line<<"\n";
                Node child;
                child.myValue = readInt(line);
                child.myName = readName(line);
                child.parent = currentNode;
                currentNode->children.push_back(child);
                i++;
                line = lines[i];
               
            }
        }
        string directory;
        if(line[2] == 'c' && line[3]== 'd'){
        directory = line.substr(5, line.size());
        
        if(directory == ".." && currentNode->myName != "/"){
            currentNode = currentNode->parent;
        }
        else{
            for(int j = 0; j<currentNode->children.size(); j++){
                if(directory == currentNode->children[j].myName){
                  currentNode = &currentNode->children[j];
                }
            }

        }

        }
        

    

    }
    while(currentNode -> myName != "/"){
        currentNode = currentNode->parent;
    }
    printTree(currentNode, "");

}