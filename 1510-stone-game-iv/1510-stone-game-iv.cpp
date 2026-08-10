class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false); // Use C++ vector<bool>

        for (int i = 0; i <= n; i++) {
            if (!dp[i]) { // Losing position
                for (int j = 1; i + j*j <= n; j++) {
                    dp[i + j*j] = true; // Mark winning positions
                }
                if (dp[n]) return true; // Optional optimization
            }
        }
        return false;
    }
};