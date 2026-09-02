class MinStack {
private:
    int currentMin = INT_MAX;
    stack<pair<int, int>> s;

public:
    MinStack() {

    }
    
    void push(int val) {
        currentMin = min(currentMin, val);
        s.push({val, currentMin});
        cout << val << ' ' << currentMin << endl;
    }
    
    void pop() {
        s.pop();
        if (s.empty())
            currentMin = INT_MAX;
        else
            currentMin = s.top().second;
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return currentMin;
    }
};
