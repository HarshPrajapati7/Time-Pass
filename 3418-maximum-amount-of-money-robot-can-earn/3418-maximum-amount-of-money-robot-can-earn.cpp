class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        // Define a large negative number for -Infinity
        const int INF = 1e9;
        
        // dp[i][j][k] table initialized to -INF
        // Using a 3D vector for simplicity and bounds safety
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -INF)));
        
        // Initialize the starting cell
        dp[0][0][0] = coins[0][0];
        
        // If the starting cell has a robber, we can choose to use 1 ability right away
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0;
        }
        
        // Traverse the grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Skip the starting cell since it's already initialized
                if (i == 0 && j == 0) continue;
                
                for (int k = 0; k < 3; ++k) {
                    int max_prev = -INF;
                    
                    // Look at the cell above
                    if (i > 0) max_prev = max(max_prev, dp[i-1][j][k]);
                    
                    // Look at the cell to the left
                    if (j > 0) max_prev = max(max_prev, dp[i][j-1][k]);
                    
                    // Update state if we don't use the ability (or can't)
                    if (max_prev != -INF) {
                        dp[i][j][k] = max(dp[i][j][k], max_prev + coins[i][j]);
                    }
                    
                    // Update state if we DO use the ability to neutralize a robber here
                    if (k > 0 && coins[i][j] < 0) {
                        int max_prev_k1 = -INF;
                        if (i > 0) max_prev_k1 = max(max_prev_k1, dp[i-1][j][k-1]);
                        if (j > 0) max_prev_k1 = max(max_prev_k1, dp[i][j-1][k-1]);
                        
                        if (max_prev_k1 != -INF) {
                            dp[i][j][k] = max(dp[i][j][k], max_prev_k1); // Adding 0 instead of losing coins
                        }
                    }
                }
            }
        }
        
        // The answer is the maximum profit at the bottom-right corner 
        // across all possible numbers of abilities used (0, 1, or 2)
        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};