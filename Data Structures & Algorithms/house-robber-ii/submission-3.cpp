class Solution {
public:
    int rob(vector<int>& nums) {
        int r11 = 0;
        int r21 = 0;
        int r12 = 0; 
        int r22 = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            int temp = max(r21, r11 + nums[i]);
            r11 = r21;
            r21 = temp;
        }

        for (int i = 1; i < nums.size(); i++) {
            int temp = max(r22, r12 + nums[i]);
            r12 = r22;
            r22 = temp;
        }
        
        return max(r21, max(r22, nums[0]));
    }
};
