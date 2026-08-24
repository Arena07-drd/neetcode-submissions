class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, double>> vec;
        stack<double> stk;

        for (int i = 0; i < position.size(); i++) {
            double time = (double)(target-position[i]) / speed[i];

            vec.push_back({position[i], time});
        }

        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        for (int i = 0; i < position.size(); i++) {
            
            if (!stk.empty() && stk.top() >= vec[i].second) {
                continue;
            }

            stk.push(vec[i].second);
        }

        int fleet = 0;

        while (!stk.empty()) {
            stk.pop();
            fleet++;
        }

        return fleet;

    }
};
