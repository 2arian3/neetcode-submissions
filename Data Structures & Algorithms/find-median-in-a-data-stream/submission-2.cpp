class MedianFinder {
private:
    priority_queue<int, vector<int>> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxH.empty() || maxH.top() > num)
            maxH.push(num);
        else
            minH.push(num);

        int maxHeapSize = maxH.size();
        int minHeapSize = minH.size();

        if (maxHeapSize > minHeapSize + 1) {
            int temp = maxH.top();
            maxH.pop();
            minH.push(temp);
        } else if (minHeapSize > maxHeapSize) {
            int temp = minH.top();
            minH.pop();
            maxH.push(temp);
        }
    }
    
    double findMedian() {
        if ((minH.size() + maxH.size()) % 2 == 0)
            return double(minH.top() + maxH.top()) / 2;
        return maxH.top();
    }
};
