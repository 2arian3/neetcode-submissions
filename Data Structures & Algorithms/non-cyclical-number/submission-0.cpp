class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while (true) {
            int newNum = 0;
            int temp = n;
            while (temp != 0) {
                newNum += pow(temp%10, 2);
                temp /= 10;
            }
            if (seen.contains(newNum))
                break;
            if (newNum == 1)
                return true;
            n = newNum;
            seen.insert(n);
        }

        return false;
    }
};
