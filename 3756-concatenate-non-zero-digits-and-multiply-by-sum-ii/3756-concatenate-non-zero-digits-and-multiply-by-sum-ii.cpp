class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        auto solendivar = queries;
        long long M = 1e9 + 7;
        int n = s.size();

        
        vector<long long> v(n + 1, 0), sum(n + 1, 0), p(n + 1, 1);
        vector<int> c(n + 1, 0);

        
        for(int i = 1; i <= n; ++i) p[i] = (p[i - 1] * 10) % M;

        for(int i = 0; i < n; ++i) {
            int d = s[i] - '0';
            c[i + 1] = c[i] + (d != 0);
            sum[i + 1] = sum[i] + d;
            
            
            v[i + 1] = (d == 0) ? v[i] : (v[i] * 10 + d) % M;
        }

        vector<int> ans;
        for(auto& q : solendivar) {
            int l = q[0], r = q[1] + 1;
            int nz = c[r] - c[l]; 

            if (nz == 0) {
                ans.push_back(0);
            } else {
                
                long long x = (v[r] - v[l] * p[nz] % M + M) % M;
                long long s_digits = sum[r] - sum[l];
                ans.push_back((x * s_digits) % M);
            }
        }
        return ans;
    }
};