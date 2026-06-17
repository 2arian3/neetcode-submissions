class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0;
        int index2 = numbers.size() - 1;

        while (index1 < index2) {
            int sum = numbers[index1] + numbers[index2];

            if (sum == target)
                break;
            
            if (sum > target)
                index2--;
            else if (sum < target)
                index1++;
        }

        vector<int> res = {index1 + 1, index2 + 1};
        return res;
    }
};
