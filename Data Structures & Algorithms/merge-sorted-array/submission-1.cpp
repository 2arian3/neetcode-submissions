class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1Temp(nums1.begin(), nums1.begin() + m);

        int n1 = 0, n2 = 0, i = 0;

        while (i < n + m) {
            if (n2 >= n || (n1 < m && nums1Temp[n1] <= nums2[n2]))
                nums1[i++] = nums1Temp[n1++];
            else
                nums1[i++] = nums2[n2++];
        }
    }
};