class Solution {
public:
    int tribonacci(int n) {
        int seq[3] = {0, 1, 1};

        if (n <= 2)
            return seq[n];

        for (int i = 3; i <= n; i++) {
            swap(seq[0], seq[1]);
            swap(seq[2], seq[1]);
            seq[2] += seq[1] + seq[0];
        }

        return seq[2];
    }
};