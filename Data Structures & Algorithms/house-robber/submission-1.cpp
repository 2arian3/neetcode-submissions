class Solution {
public:
    int rob(vector<int>& nums) {
        int r1 = 0;
        int r2 = 0;

        for (int num: nums) {
            int temp = max(r2, r1 + num);
            r1 = r2;
            r2 = temp;
        }

        return r2;
    }
};
