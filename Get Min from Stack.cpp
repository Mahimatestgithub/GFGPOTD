class Solution {
  private:
    stack<int> s;
    stack<int> minStack; // Auxiliary stack to track the minimum element

  public:
    Solution() {}

    // Add an element to the top of Stack
    void push(int x) {
        s.push(x);
        // Push to minStack if it's empty or x is smaller or equal to the current min
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if (!s.empty()) {
            if (s.top() == minStack.top()) {
                minStack.pop();
            }
            s.pop();
        }
    }

    // Returns top element of the Stack
    int peek() {
        return s.empty() ? -1 : s.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};
