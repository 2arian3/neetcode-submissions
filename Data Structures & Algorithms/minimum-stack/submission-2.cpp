class MinStack {
private:
    stack<pair<int, int>> s;
    int currentMin;
public:
    MinStack() {
        this->currentMin = numeric_limits<int>::max();
    }
    
    void push(int val) {
        this->currentMin = this->currentMin > val ? val : this->currentMin;
        s.push({val, this->currentMin});
    }
    
    void pop() {
        s.pop();
        
        if (!s.empty()) {
            this->currentMin = s.top().second;
        } else {
            this->currentMin = numeric_limits<int>::max();
        }
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
