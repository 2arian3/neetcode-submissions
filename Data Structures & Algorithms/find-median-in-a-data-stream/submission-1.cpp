class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (minHeap.empty() || num > minHeap.top())
            minHeap.push(num);
        else
            maxHeap.push(num);

        if (minHeap.size() > maxHeap.size() + 1) {
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        } else if (maxHeap.size() > minHeap.size()) { 
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size())
            return (minHeap.top() + maxHeap.top()) / 2.0;
        else
            return minHeap.top() / 1.0;
    }
};
