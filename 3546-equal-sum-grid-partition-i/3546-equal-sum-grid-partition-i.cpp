class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long total_sum = 0;

        // Arrays to store the sum of each entire row and each entire column
        vector<long long> row_sums(m, 0);
        vector<long long> col_sums(n, 0);

        // 1. Calculate row sums, column sums, and total sum all in one pass
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row_sums[i] += grid[i][j];
                col_sums[j] += grid[i][j];
                total_sum += grid[i][j];
            }
        }

        // If the total sum is odd, we can't divide it equally
        if (total_sum % 2 != 0) {
            return false;
        }

        long long target = total_sum / 2;

        // 2. Check for a valid Horizontal Cut
        long long current_sum = 0;
        // We stop at m - 1 because both sections must be "non-empty"
        // (You can't cut AFTER the last row)
        for (int i = 0; i < m - 1; ++i) { 
            current_sum += row_sums[i];
            if (current_sum == target) {
                return true;
            }
        }

        // 3. Check for a valid Vertical Cut
        current_sum = 0;
        // We stop at n - 1 for the same "non-empty" rule
        for (int j = 0; j < n - 1; ++j) { 
            current_sum += col_sums[j];
            if (current_sum == target) {
                return true;
            }
        }

        return false;
    }
};