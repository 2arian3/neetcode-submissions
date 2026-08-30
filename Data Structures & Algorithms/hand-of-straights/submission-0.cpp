class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        sort(hand.begin(), hand.end());

        unordered_map<int, int> counter;

        for (const auto& card: hand)
            counter[card]++;
        
        for (const auto& card: hand) {
            if (counter[card] == 0)
                continue;
            for (int c = card; c < card + groupSize; c++) {
                if (counter[c] == 0)
                    return false;
                counter[c]--;
            }
        }

        return true;
    }
};
