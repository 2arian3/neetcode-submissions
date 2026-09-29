class FreqStack {
private:
    unordered_map<int, int> freqs;
    unordered_map<int, vector<int>> s;
    int maxFreq;
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        ++freqs[val];
        maxFreq = max(maxFreq, freqs[val]);
        s[freqs[val]].push_back(val);
    }
    
    int pop() {
        int value = s[maxFreq].back();
        s[maxFreq].pop_back();
        while (maxFreq > 0 && s[maxFreq].empty())
            maxFreq--;
        freqs[value]--;
        return value;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */