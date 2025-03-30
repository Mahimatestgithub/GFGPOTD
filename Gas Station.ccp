class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int start_station = 0;
        int current_tank = 0;
        int total_gas = 0;
        int total_cost = 0;

        for (int i = 0; i < gas.size(); i++) {
            total_gas += gas[i];      // Sum of all gas
            total_cost += cost[i];    // Sum of all costs
            current_tank += gas[i] - cost[i]; // Tank shows the net gas left

            // If tank goes negative, reset the starting station
            if (current_tank < 0) {
                start_station = i + 1;  // Next station becomes the new start
                current_tank = 0;       // Reset tank for the next potential start
            }
        }

        // If total gas is less than total cost, no solution exists
        return (total_gas < total_cost) ? -1 : start_station;
    }
};
