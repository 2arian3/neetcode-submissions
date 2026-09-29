class MinStack {
private:
    stack<pair<int, int>> s;
    int currentMin = INT_MAX;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        currentMin = min(currentMin, val);
        s.push({val, currentMin});
        cout << val << " " << currentMin << endl;
    }
    
    void pop() {
        s.pop();
        currentMin = !s.empty() ? s.top().second : INT_MAX;
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return currentMin;
    }
};
