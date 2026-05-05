class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }
        
        int n = matrix.size();

        // Transpose the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // 2. Reverse each row
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};