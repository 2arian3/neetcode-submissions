class MinStack {
private:
    int currMin;
    stack<pair<int, int>> s;

public:
    MinStack() {
        currMin = INT_MAX;
    }
    
    void push(int val) {
        s.push({val, currMin});
        currMin = min(currMin, val);
    }
    
    void pop() {
        currMin = s.top().second;
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return currMin;
    }
};
