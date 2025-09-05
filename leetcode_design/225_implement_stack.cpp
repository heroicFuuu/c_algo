#include <vector>
using std::vector;

class MyStack {
public:
    vector<int> q;
    int n;
    MyStack() {
        n = -1;
        q.reserve(100);
    }
    
    void push(int x) {
        n ++;
        q[n] = x;
    }
    
    int pop() {
        int ret = q[n];
        n--;
        return ret;
    }
    
    int top() {
        return q[n];
    }
    
    bool empty() {
        return n == -1 ;
    }
};

