class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;
        
        // This will hold our final answers
        vector<vector<int>> p(n, vector<int>(m));
        
        // Pass 1: Calculate the prefix products (Top-Left to Bottom-Right)
        long long pref = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                p[i][j] = pref; // Store product of everything BEFORE this cell
                // Update prefix for the next cell
                pref = (pref * grid[i][j]) % MOD; 
            }
        }
        
        // Pass 2: Calculate suffix products and combine (Bottom-Right to Top-Left)
        long long suff = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                // Multiply the prefix (already in p) by the suffix
                p[i][j] = (p[i][j] * suff) % MOD; 
                // Update suffix for the next cell
                suff = (suff * grid[i][j]) % MOD;
            }
        }
        
        return p;
    }
};