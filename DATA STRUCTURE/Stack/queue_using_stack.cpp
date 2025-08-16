class MyQueue {
public:
    stack<int> p;  //1*
    stack<int> q;   // 2*
    MyQueue() {

    }

    void push(int x) {
        while (!p.empty()) {
            int k = p.top();
            p.pop();
            q.push(k);
        }
        p.push(x);

        while (!q.empty()) {
            int k = q.top();
            q.pop();
            p.push(k);
        }
    }

    int pop() {
        int ans = p.top();
        p.pop();
        return ans;
    }

    int peek() {
        return p.top();
    }

    bool empty() {
        return p.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */