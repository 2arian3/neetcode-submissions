class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for (int i = 0; i < position.size(); i++)
            cars.emplace_back(position[i], speed[i]);

        sort(cars.begin(), cars.end());

        int fleets = 0;
        double fleetTime = 0.0;

        for (int i = cars.size() - 1; i >= 0; i--) {
            double time = (double)(target - cars[i].first) / cars[i].second;

            if (time > fleetTime) {
                fleets++;
                fleetTime = time;
            }
        }

        return fleets;
    }
};