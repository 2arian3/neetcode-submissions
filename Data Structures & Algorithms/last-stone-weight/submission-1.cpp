class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxH;

        for (const auto& stone: stones)
            maxH.push(stone);

        while (maxH.size() > 1) {
            int s1 = maxH.top();
            maxH.pop();

            int s2 = maxH.top();
            maxH.pop();

            if (s1 == s2)
                continue;

            int newS = s1 < s2 ? s2 - s1 : s1 - s2;
            maxH.push(newS);
        }

        return maxH.empty() ? 0 : maxH.top();
    }
};
