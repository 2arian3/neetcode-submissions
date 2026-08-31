class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int currFuel = 0, startIndex = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currFuel += gas[i] - cost[i];

            if (currFuel < 0) {
                startIndex = i + 1;
                currFuel = 0;
            }
        }

        return (totalGas >= totalCost) ? startIndex : -1;
    }
};