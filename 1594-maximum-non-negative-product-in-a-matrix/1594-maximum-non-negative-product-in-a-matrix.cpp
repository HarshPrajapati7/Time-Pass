class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int MOD= 1e9+7;

        // two dps table

        vector<vector<long long >> max_dp(m,vector<long long>(n));
        vector<vector<long long >> min_dp(m,vector<long long>(n));

        // abse case 
        max_dp[0][0]=grid[0][0];
        min_dp[0][0]=grid[0][0];

        // fil the first row 

        for(int j=1;j<n;++j){
            max_dp[0][j]=max_dp[0][j-1]*grid[0][j];
            min_dp[0][j]=min_dp[0][j-1]*grid[0][j];

        }
        //first column

        for (int i = 1; i < m; ++i) {
            max_dp[i][0] = max_dp[i-1][0] * grid[i][0];
            min_dp[i][0] = min_dp[i-1][0] * grid[i][0];
        }

        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                long long current_val=grid[i][j];;
                long long path1 = current_val * max_dp[i-1][j]; // Top Max
                long long path2 = current_val * min_dp[i-1][j]; // Top Min
                long long path3 = current_val * max_dp[i][j-1]; // Left Max
                long long path4 = current_val * min_dp[i][j-1]; // Left Min

                max_dp[i][j]=max({path1,path2,path3,path4});

                min_dp[i][j]=min({path1,path2,path3,path4});

            }
        }
        long long max_result = max_dp[m-1][n-1];

        if(max_result<0){
            return -1;
        }



        return max_result % MOD;
        
    }
};