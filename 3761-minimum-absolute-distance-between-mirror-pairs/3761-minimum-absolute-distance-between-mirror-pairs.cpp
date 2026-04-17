class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        // Map to store: {reversed_value -> most_recent_index}
        unordered_map<int, int> reversed_indices;
        int min_dist = -1;

        for (int j = 0; j < nums.size(); ++j) {
            // Check if the current number matches any previously seen reversed number
            if (reversed_indices.count(nums[j])) {
                int i = reversed_indices[nums[j]];
                int current_dist = j - i;
                
                // Update the minimum distance
                if (min_dist == -1 || current_dist < min_dist) {
                    min_dist = current_dist;
                }
            }
            
            // Reverse the current number and store/update its index in the map
            int rev = reverseInteger(nums[j]);
            reversed_indices[rev] = j; 
        }

        return min_dist;
    }

private:
    // Helper function to mathematically reverse an integer
    int reverseInteger(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }
};