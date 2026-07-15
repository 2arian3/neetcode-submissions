class Solution {
public:
    int jump(vector<int>& nums) {
        int res, l, r, farthest;
        res = l = r = farthest = 0;

        while (farthest < nums.size() - 1) {
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, nums[i] + i); 
            }
            l = r + 1;
            r = farthest;
            res++;
        }

        return res;
    }
};
