class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res(digits.size() + 1, 0);

        int carry = 1;
        for (int i = digits.size(); i > 0; i--) {
            int sum = digits[i - 1] + carry;
            res[i] = sum % 10;
            carry = sum / 10;
        }
        res[0] = carry;

        if (carry == 0) {
            res.erase(res.begin());
        }

        return res;
    }
};
