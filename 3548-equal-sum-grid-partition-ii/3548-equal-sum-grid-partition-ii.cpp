class Solution {
private:
    // Helper to check if we can safely discount a cell without breaking connectivity
    bool canRemove(long long diff, int r_start, int r_end, int c_start, int c_end, 
                   const vector<int>& counts, const vector<vector<int>>& grid) {
        
        // If the difference is larger than the max possible cell value, it's impossible
        if (diff > 100000 || diff <= 0) return false;
        
        int rows = r_end - r_start + 1;
        int cols = c_end - c_start + 1;
        
        // Rule 1: If the section is a 1D horizontal row, only the left/right ends are valid
        if (rows == 1) { 
            return grid[r_start][c_start] == diff || grid[r_start][c_end] == diff;
        } 
        // Rule 2: If the section is a 1D vertical column, only the top/bottom ends are valid
        else if (cols == 1) { 
            return grid[r_start][c_start] == diff || grid[r_end][c_start] == diff;
        } 
        // Rule 3: If it's 2D (thickness >= 2), removing ANY cell leaves the rest connected
        else { 
            return counts[diff] > 0;
        }
    }

    // Sweeps horizontal cuts from top to bottom
    bool checkHorizontal(const vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Frequency arrays to track what numbers are available in the Top and Bottom sections
        vector<int> top_counts(100005, 0);
        vector<int> bot_counts(100005, 0);
        long long total_sum = 0;
        
        // Initially, the Bottom section contains everything
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bot_counts[grid[i][j]]++;
                total_sum += grid[i][j];
            }
        }
        
        long long top_sum = 0;
        
        // Move the cut down row by row (stopping before the last row to keep sections non-empty)
        for (int i = 0; i < m - 1; ++i) {
            // Shift the current row from Bottom to Top
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                bot_counts[val]--;
                top_counts[val]++;
                top_sum += val;
            }
            long long bot_sum = total_sum - top_sum;
            
            // Case 1: Perfect match, no discount needed
            if (top_sum == bot_sum) return true;
            
            // Case 2: Top is heavier, try to discount a cell from the Top section
            if (top_sum > bot_sum) {
                long long diff = top_sum - bot_sum;
                if (canRemove(diff, 0, i, 0, n - 1, top_counts, grid)) return true;
            } 
            // Case 3: Bottom is heavier, try to discount a cell from the Bottom section
            else { 
                long long diff = bot_sum - top_sum;
                if (canRemove(diff, i + 1, m - 1, 0, n - 1, bot_counts, grid)) return true;
            }
        }
        return false;
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        // 1. Check all Horizontal cuts
        if (checkHorizontal(grid)) return true;
        
        // 2. Create a transposed version of the grid to simulate Vertical cuts
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> transposed(n, vector<int>(m));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                transposed[j][i] = grid[i][j];
            }
        }
        
        // 3. Check Vertical cuts by running the transposed grid through the same function
        return checkHorizontal(transposed);
    }
};