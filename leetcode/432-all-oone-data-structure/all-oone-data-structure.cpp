class AllOne {
private:
    // Doubly Linked List Node structure to hold a set of keys for a specific count
    struct Node {
        int count;
        unordered_set<string> keys;
        Node* prev;
        Node* next;
        Node(int _count) : count(_count), prev(nullptr), next(nullptr) {}
    };

    // Hash maps for key->count and count->node mappings
    unordered_map<string, int> keyCount;  // Stores the count of each key
    unordered_map<int, Node*> countNode;  // Maps count to corresponding Node in doubly linked list
    Node* head;  // Dummy head node of doubly linked list
    Node* tail;  // Dummy tail node of doubly linked list

    // Helper function to insert a node after a given node
    void insertNodeAfter(Node* node, Node* newNode) {
        newNode->next = node->next;
        newNode->prev = node;
        if (node->next) {
            node->next->prev = newNode;
        }
        node->next = newNode;
    }

    // Helper function to remove a node from the linked list
    void removeNode(Node* node) {
        if (node->prev) {
            node->prev->next = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        }
        countNode.erase(node->count);
        delete node;
    }

public:
    // Constructor initializes the data structure
    AllOne() {
        head = new Node(0);  // Dummy head node
        tail = new Node(0);  // Dummy tail node
        head->next = tail;
        tail->prev = head;
    }

    // Increment the count of a key
    void inc(string key) {
        int currentCount = keyCount[key];
        keyCount[key]++;  // Increase key's count by 1
        int newCount = keyCount[key];

        Node* currentNode = (currentCount == 0) ? nullptr : countNode[currentCount];
        Node* nextNode = countNode[newCount];

        // Create new node for newCount if it doesn't exist
        if (!nextNode) {
            nextNode = new Node(newCount);
            countNode[newCount] = nextNode;
            if (currentNode) {
                insertNodeAfter(currentNode, nextNode);
            } else {
                insertNodeAfter(head, nextNode);
            }
        }

        // Move key to the nextNode (new count)
        nextNode->keys.insert(key);
        if (currentNode) {
            currentNode->keys.erase(key);
            if (currentNode->keys.empty()) {
                removeNode(currentNode);  // Remove node if no keys are left
            }
        }
    }

    // Decrement the count of a key
    void dec(string key) {
        int currentCount = keyCount[key];
        if (currentCount == 0) return;  // No such key to decrement

        keyCount[key]--;  // Decrease key's count by 1
        int newCount = keyCount[key];

        Node* currentNode = countNode[currentCount];
        Node* prevNode = (newCount == 0) ? nullptr : countNode[newCount];

        // Remove key if its count becomes 0
        if (newCount == 0) {
            keyCount.erase(key);
        } else if (!prevNode) {
            prevNode = new Node(newCount);
            countNode[newCount] = prevNode;
            insertNodeAfter(currentNode->prev, prevNode);
        }

        // Move key to prevNode (new count) or remove if count becomes 0
        if (newCount > 0) {
            prevNode->keys.insert(key);
        }
        currentNode->keys.erase(key);
        if (currentNode->keys.empty()) {
            removeNode(currentNode);  // Remove node if no keys are left
        }
    }

    // Get the key with the maximum count
    string getMaxKey() {
        if (tail->prev == head) return "";  // No keys present
        return *(tail->prev->keys.begin());  // Return any key from the set of max count
    }

    // Get the key with the minimum count
    string getMinKey() {
        if (head->next == tail) return "";  // No keys present
        return *(head->next->keys.begin());  // Return any key from the set of min count
    }
};
