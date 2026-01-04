#include <stack>
using std::stack;
class MinStack {
  public:
    stack<int> stk;
    stack<int> minStk;

    MinStack() {}

    void push(int val) {
        stk.push(val);
        if (minStk.empty() || minStk.top() >= val) {
            minStk.push(val);
        }
    }

    void pop() {
        if (minStk.top() == stk.top())
            minStk.pop();
        stk.pop();
    }

    int top() {
        if (!stk.empty())
            return stk.top();
        return -1;
    }

    int getMin() {
        return minStk.top();
    }
};
