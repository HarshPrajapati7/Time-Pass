class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        
        // Sort factories in ascending order by their positions
        sort(factory.begin(), factory.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int n = robot.size();
        int m = factory.size();

        // Memoization table: initialized to -1
        // Size is N x M, storing long long to prevent overflow
        vector<vector<long long>> memo(n, vector<long long>(m, -1));

        return solve(0, 0, robot, factory, memo);
    }

private:
    long long solve(int i, int j, const vector<int>& robot, const vector<vector<int>>& factory, vector<vector<long long>>& memo) {
        int n = robot.size();
        int m = factory.size();

        // Base case 1: All robots have been assigned to a factory
        if (i == n) {
            return 0;
        }

        // Base case 2: We ran out of factories, but robots are still left
        if (j == m) {
            return 1e18; // Return a sufficiently large number to act as infinity
        }

        // If this state has already been computed, return the cached result
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        // Option 1: Skip the current factory j and move to factory j+1
        long long min_dist = solve(i, j + 1, robot, factory, memo);

        // Option 2: Use the current factory j to repair k robots
        long long current_factory_pos = factory[j][0];
        int current_factory_limit = factory[j][1];

        long long dist_sum = 0;
        
        // Try repairing from 1 up to 'limit' robots at this factory
        for (int k = 1; k <= current_factory_limit; ++k) {
            // Check if there are still robots left to assign
            if (i + k - 1 < n) {
                // Add the distance traveled by the newly assigned robot
                dist_sum += abs(robot[i + k - 1] - current_factory_pos);
                
                // Calculate total distance if the rest of the robots go to subsequent factories
                long long next_dist = solve(i + k, j + 1, robot, factory, memo);
                
                // Only consider valid paths
                if (next_dist != 1e18) {
                    min_dist = min(min_dist, dist_sum + next_dist);
                }
            } else {
                // No more broken robots left
                break;
            }
        }

        // Cache the computed minimum distance for this state
        return memo[i][j] = min_dist;
        
    }
};