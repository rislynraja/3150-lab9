#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

struct Node {
    string name;
    Node(string name) : name{name} {}
    shared_ptr<Node> next; //Not weak!
   
    ~Node() { cout << "Node [" << name << "] destructor" << endl; }
   };