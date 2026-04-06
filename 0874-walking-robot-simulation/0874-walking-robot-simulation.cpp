class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obs_set;
        for (const auto& obs : obstacles) {
            obs_set.insert(to_string(obs[0]) + "_" + to_string(obs[1]));
        }

        // Directions: North, East, South, West
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int dir = 0; // Starts facing North

        int x = 0, y = 0;
        int max_dist_sq = 0;

        for (int cmd : commands) {
            if (cmd == -2) {
                dir = (dir + 3) % 4; // Turn Left
            } else if (cmd == -1) {
                dir = (dir + 1) % 4; // Turn Right
            } else {
                for (int i = 0; i < cmd; ++i) {
                    int next_x = x + dx[dir];
                    int next_y = y + dy[dir];
                    
                    if (obs_set.count(to_string(next_x) + "_" + to_string(next_y))) {
                        break; // Blocked by obstacle
                    }
                    
                    x = next_x;
                    y = next_y;
                    max_dist_sq = max(max_dist_sq, x * x + y * y);
                }
            }
        }
        return max_dist_sq;
        
    }
};