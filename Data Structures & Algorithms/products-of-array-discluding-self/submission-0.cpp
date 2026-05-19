class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products = {};

        unordered_map<int, int> pre_products = {};
        unordered_map<int, int> post_products = {};

        // Calculating pre products
        pre_products[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            pre_products[i] = nums[i-1] * pre_products[i-1];
        }

        // Calculating post products
        post_products[nums.size()-1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            post_products[i] = nums[i+1] * post_products[i+1];
        }

        for (int i = 0; i < nums.size(); i++) {
            products.push_back(pre_products[i] * post_products[i]);
        }

        return products;
    }
};
