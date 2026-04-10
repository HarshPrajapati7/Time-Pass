class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        // This map stores the list of indices where each number appears
        unordered_map<int, vector<int>> indices;
        int min_dist = INT_MAX;
        
        // Group indices by the numbers
        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]].push_back(i);
        }
        
        // Find the minimum distance for elements appearing at least 3 times
        for (auto& [val, idx_list] : indices) {
            if (idx_list.size() >= 3) {
                // Since we inserted indices in order, the idx_list is already sorted.
                // We check every consecutive triplet to find the smallest span.
                for (int i = 0; i < idx_list.size() - 2; i++) {
                    
                    // The distance formula simplifies to 2 * (last_index - first_index)
                    int current_dist = 2 * (idx_list[i + 2] - idx_list[i]);
                    min_dist = min(min_dist, current_dist);
                }
            }
        }
        
        // If no number appeared 3 times, return -1 as per the problem requirements
        return min_dist == INT_MAX ? -1 : min_dist;
    }
};