class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int minSpeed = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long totalHours = 0;

            for (auto p: piles)
                totalHours += ceil((double)(p) / mid);

            if (totalHours <= h) {
                minSpeed = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }

        return minSpeed;
    }
};
