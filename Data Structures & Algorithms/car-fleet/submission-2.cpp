class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, int>> cars;

        // time = time left to reach the end
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());

        double Lasttime = (double)(target - cars[0].first) / cars[0].second;
        int fleet = 1;

        for (int i = 1; i < cars.size(); i++) {

            double currenttime =
                (double)(target - cars[i].first) / cars[i].second;

            if (currenttime > Lasttime) {
                fleet++;
                Lasttime = currenttime;
            }

        }

        return fleet;
    }
};
