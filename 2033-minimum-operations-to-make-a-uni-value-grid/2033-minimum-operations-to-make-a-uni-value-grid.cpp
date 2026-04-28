class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        // Step 1: Flatten
        for (auto &row : grid) {
            for (int val : row) {
                nums.push_back(val);
            }
        }

        // Step 2: Check feasibility
        int mod = nums[0] % x;
        for (int val : nums) {
            if (val % x != mod) return -1;
        }

        // Step 3: Sort
        sort(nums.begin(), nums.end());

        // Step 4: Median
        int median = nums[nums.size() / 2];

        // Step 5: Count operations
        int count = 0;
        for (int val : nums) {
            count += abs(val - median) / x;
        }

        return count;
    }
};