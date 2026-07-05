class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (auto const stone: stones)
            maxHeap.push(stone);

        while (maxHeap.size() > 1) {
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();

            if (x < y)
                maxHeap.push(y - x);
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
