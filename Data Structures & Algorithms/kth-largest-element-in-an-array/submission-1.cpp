class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minH;

        for (const auto& num: nums) {
            minH.push(num);
            if (minH.size() > k)
                minH.pop();
        }

        return minH.top();
    }
};
