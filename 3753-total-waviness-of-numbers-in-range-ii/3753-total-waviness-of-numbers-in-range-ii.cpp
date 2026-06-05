#include <bits/stdc++.h>
using namespace std;

// returns pair {count_of_numbers, total_waviness_sum} for numbers built from pos..end
struct Res { long long cnt; long long sum; };

class Solution {
public:
    
    long long totalWavinessRange(long long bound) {
        if (bound < 0) return 0;
        string s = to_string(bound);
        len = s.size();
        digits = s;
        // reset memo used for tight==0 states
        for (int p=0;p<=len;p++)
            for(int st=0;st<2;st++)
                for(int a=0;a<11;a++)
                    for(int b=0;b<11;b++) {
                        seen[p][st][a][b] = false;
                    }
        Res r = dfs(0, 1, 0, 10, 10); 
        return r.sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        return totalWavinessRange(num2) - totalWavinessRange(num1 - 1);
    }

private:
    string digits;
    int len;
    
    Res memo[21][2][11][11];
    bool seen[21][2][11][11];

    Res dfs(int pos, int tight, int started, int prev1, int prev2) {
        if (pos == len) {
           
            return {1, 0};
        }

        if (!tight && seen[pos][started][prev1][prev2]) {
            return memo[pos][started][prev1][prev2];
        }

        int limit = tight ? (digits[pos] - '0') : 9;
        long long totalCnt = 0;
        long long totalSum = 0;

        for (int d = 0; d <= limit; ++d) {
            int newTight = tight && (d == limit);
            int newStarted = started || (d != 0);

            int newPrev2 = 10, newPrev1 = 10;
            if (!newStarted) {
                newPrev1 = newPrev2 = 10;
            } else {
                if (!started && newStarted) {
                   
                    newPrev2 = 10;
                    newPrev1 = d;
                } else if (started) {
                    
                    newPrev2 = prev1;
                    newPrev1 = d;
                }
            }

            Res child = dfs(pos + 1, newTight, newStarted, newPrev1, newPrev2);

            
            int contrib = 0;
            if (started && prev1 != 10 && prev2 != 10 && newStarted) {
               
                if ((prev1 > prev2 && prev1 > d) || (prev1 < prev2 && prev1 < d)) contrib = 1;
            }

            totalCnt += child.cnt;
            totalSum += child.sum + child.cnt * (long long)contrib;
        }

        Res ans{totalCnt, totalSum};
        if (!tight) {
            seen[pos][started][prev1][prev2] = true;
            memo[pos][started][prev1][prev2] = ans;
        }
        return ans;
    }
};

