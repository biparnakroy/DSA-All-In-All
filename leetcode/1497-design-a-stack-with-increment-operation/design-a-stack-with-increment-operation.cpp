class CustomStack {
private:
    vector<int> stack;  // Stack to hold the elements
    vector<int> inc;    // Array to store incremental values
    int maxSize;        // Maximum size of the stack

public:
    // Constructor to initialize the stack with a given maxSize
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        stack.resize(0);
        inc.resize(maxSize, 0);  // Initialize the increment array with 0
    }

    // Push the element x onto the stack
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);  // Only push if stack size is less than maxSize
        }
    }

    // Pop the top element from the stack and return it
    int pop() {
        int idx = stack.size() - 1;  // Top index of the stack
        if (idx == -1) {
            return -1;  // Stack is empty
        }
        
        int res = stack.back() + inc[idx];  // Add any pending increment
        stack.pop_back();  // Remove the top element

        if (idx > 0) {
            inc[idx - 1] += inc[idx];  // Propagate the increment down
        }
        inc[idx] = 0;  // Clear the increment for the current element

        return res;  // Return the popped element after applying increment
    }

    // Increment the bottom k elements by val
    void increment(int k, int val) {
        int idx = min(k, (int)stack.size()) - 1;  // Find the last index to increment
        if (idx >= 0) {
            inc[idx] += val;  // Add the increment to the inc array at index idx
        }
    }
};
