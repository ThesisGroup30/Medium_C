class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;
        
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], (target - position[i]) / static_cast<double>(speed[i])});
        }
        
        sort(cars.begin(), cars.end(), greater<pair<int, double>>());
        
        int fleets = 0;
        double currMaxTime = 0.0;
        
        for (int i = 0; i < n; i++) {
            if (cars[i].second > currMaxTime) {
                fleets++;
                currMaxTime = cars[i].second;
            }
        }
        
        return fleets;
    }
};
