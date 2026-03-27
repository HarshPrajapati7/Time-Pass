class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        // If k is larger than the row size, simplify it. 
        // Shifting a row of size 5 by 6 steps is the exact same as shifting it by 1 step.
        k = k % n; 

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Check if the current element matches the element 'k' steps away
                if (mat[i][j] != mat[i][(j + k) % n]) {
                    return false; // If even one element fails, the matrices aren't similar
                }
            }
        }
        
        return true; 
    }
};