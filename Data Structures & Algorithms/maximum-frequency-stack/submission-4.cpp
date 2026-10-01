class FreqStack {
private:
    int maxFreq;
    unordered_map<int, vector<int>> freqMap;
    unordered_map<int, int> cnt;

public:
    FreqStack() {
        maxFreq = INT_MIN;
    }
    
    void push(int val) {
        cnt[val]++;
        maxFreq = max(maxFreq, cnt[val]);
        freqMap[cnt[val]].push_back(val);
    }
    
    int pop() {
        int numToPop = freqMap[maxFreq].back();
        freqMap[maxFreq].pop_back();
        if (freqMap[maxFreq].empty())
            maxFreq--;
        cnt[numToPop]--;
        return numToPop;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */