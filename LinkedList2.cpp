#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Node2.cpp"

using namespace std;

class LinkedList {
    private:
        shared_ptr<Node> root = nullptr;
        int numNodes = 0;
        vector<string> names = { "zero", "one", "two", "three", "four", "five" }; // mostly the same as before

    public:
        void SERVER_buildCircularLinkedList() {
            numNodes = names.size();
            root = make_shared<Node>(names[0]);
            shared_ptr<Node> node = root;
            for (int i = 1; i < numNodes; i++) {
                node->next = make_shared<Node>(names[i]);
                node = node->next;
            }
            node->next = root; // the same as before but now, there's no connecting to the weak ptr
        }

        void SERVER_printLinkedList() { // this function stays the same (because it didn't need the weak ptr before)
            auto cur = root;
            for (int i = 0; i < numNodes && cur; i++) {
                cout << "[" << cur->name << "] : use_count: " << cur.use_count()
                    << " address: " << cur.get()
                    << " next (shared_ptr): " << cur->next.get() << endl;
                cur = cur->next;
            }
        }

        void SERVER_deleteCircularLinkedList() {
            if (!root) return; // already deleted (or never existed?)
            shared_ptr<Node> node = root;
            shared_ptr<Node> lag = root;
            for (int i =0; i < 6; i++) {
                lag = node;
                node = node->next ;
                lag->next.reset();
            }
        }

        void CLIENT_printLinkedList() {
            auto cur = root;
            if (!cur) {
                cout << "Client after linked list deleted: [Nothing]" << endl;
                return;
            }
            for (int i = 0; i < numNodes && cur; i++) {
                cout << "[" << cur->name << "] : use_count: " << cur.use_count()
                    << " address: " << cur.get()
                    << " next (shared_ptr): " << cur->next.get() << endl;
                cur = cur->next;
            }
        }


        // TESTING FUNCTIONS FOR TEST CASES
        vector<string> getNodeNames() const { // just like get server node names
            vector<string> result;
            auto cur = root;
            for (int i = 0; i < numNodes && cur; i++) {
                result.push_back(cur->name);
                cur = cur->next;
            }
            return result;
        }

        int useCountAtRoot() const {
            return root ? root.use_count() : 0;
        }
};
