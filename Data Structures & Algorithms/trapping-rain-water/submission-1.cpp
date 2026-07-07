class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMaxH = height[l];
        int rightMaxH = height[r];
        int res = 0;

        while (l < r) {
            if (leftMaxH < rightMaxH) {
                leftMaxH = max(leftMaxH, height[++l]);
                res += leftMaxH - height[l];
            } else {
                rightMaxH = max(rightMaxH, height[--r]);
                res += rightMaxH - height[r];
            }
        }

        return res;
    }
};
