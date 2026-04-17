class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        // Step 1: Group indices by their values
        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < n; ++i) {
            positions[nums[i]].push_back(i);
        }
        
        // Step 2: Precompute the minimum distance for every index
        vector<int> min_dist(n, -1);
        
        for (auto const& [value, pos_list] : positions) {
            int m = pos_list.size();
            
            // If the number appears only once, distance remains -1
            if (m <= 1) continue;
            
            for (int i = 0; i < m; ++i) {
                int curr_idx = pos_list[i];
                
                // Get the adjacent indices in the list (wrapping around using modulo)
                int prev_idx = pos_list[(i - 1 + m) % m];
                int next_idx = pos_list[(i + 1) % m];
                
                // Calculate circular distances
                int dist_to_prev = abs(curr_idx - prev_idx);
                dist_to_prev = min(dist_to_prev, n - dist_to_prev);
                
                int dist_to_next = abs(curr_idx - next_idx);
                dist_to_next = min(dist_to_next, n - dist_to_next);
                
                // Store the absolute minimum distance for the current index
                min_dist[curr_idx] = min(dist_to_prev, dist_to_next);
            }
        }
        
        // Step 3: Answer the queries in O(1) time
        vector<int> answer;
        answer.reserve(queries.size());
        for (int q : queries) {
            answer.push_back(min_dist[q]);
        }
        
        return answer;
    }
};


