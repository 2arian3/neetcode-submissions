class Solution {
private:
    double getDistance(vector<int> point) {
        return sqrt(pow(point[0], 2) + pow(point[1], 2));
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [this](const vector<int>& a, const vector<int>& b) {
            return getDistance(a) > getDistance(b);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);

        for (auto const point: points)
            minHeap.push(point);

        vector<vector<int>> res;

        for (int i = 0; i < k; i++) {
            res.push_back(minHeap.top());
            minHeap.pop();
        }

        return res;
    }
};
