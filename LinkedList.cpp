#include "Node.cpp"

class LinkedList {
    private:
        shared_ptr<Node> root = nullptr;
        int numNodes = 0;
        vector<string> names = { "zero", "one", "two", "three", "four", "five" }; // these are the nodes
    
    public:
        void SERVER_buildCircularLinkedList() {
            numNodes = names.size(); // setting num nodes
            root = make_shared<Node>(names[0]); // first node is the root
            shared_ptr<Node> node = root;
            for (int i = 1; i < numNodes; i++) { // setting the next connections for all nodes
                node->next = make_shared<Node>(names[i]);
                node = node->next;
            }
            node->next = root; // connects back to the start
            node = root;
            for (int i = 0; i < numNodes; i++) { // also setting the weak connections for all nodes
                node->weakNext = node->next;
                node = node->next;
            }
        }
    
        void SERVER_printLinkedList() {
            shared_ptr<Node> cur = root;
            for (int i = 0; i < numNodes; i++) { // just traversing and printing
                cout << "[" << cur->name << "] : use_count: " << cur.use_count()
                     << " address: " << cur.get()
                     << " next (from shared_ptr): " << cur->next.get() << endl;
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
            shared_ptr<Node> cur = root;
            if (!cur) {
                cout << "Client after linked list deleted: [Nothing]" << endl;
                return;
            }
            for (int i = 0; i < numNodes; i++) {
                cout << "[" << cur->name << "] : use_count: " << cur.use_count()
                     << " address: " << cur.get();
                if (auto nextShared = cur->weakNext.lock()) {
                    cout << " next (from weak_ptr): " << nextShared.get() << endl;
                    cur = nextShared;
                } else {
                    cout << " next (from weak_ptr): 0" << endl;
                    cout << "Yipes! shared_ptr not available" << endl;
                }
            }
        }


        // TESTING FUNCTIONS FOR TEST CASES
        vector<string> getServerNodeNames() const { // puts all node names in vector and returns it
            vector<string> result;
            auto cur = root;
            for (int i = 0; i < numNodes && cur; i++) { 
                result.push_back(cur->name);
                cur = cur->next;
            }
            return result;
        }
        
        vector<string> getClientNodeNamesUsingWeakPtrs() const { // does the same thing but uses weak ptrs
            vector<string> result;
            auto cur = root;
            for (int i = 0; i < numNodes && cur; i++) {
                result.push_back(cur->name);
                auto nextShared = cur->weakNext.lock(); // lock
                if (!nextShared) break; 
                cur = nextShared;
            }
            return result;
        }
        
    };
    