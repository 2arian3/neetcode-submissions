class Solution {
public:
    int reverse(int x) {
        long res = recursive(abs(x), 0) * (x > 0 ? 1 : -1);
        if (res > INT_MAX || res < INT_MIN) {
            return 0;
        }
        return (int)res;
    }

    long recursive(int n, long reverse) {
        if (n == 0)
            return reverse;
        reverse = reverse * 10 + n % 10;
        return recursive(n / 10, reverse);
    }
};
