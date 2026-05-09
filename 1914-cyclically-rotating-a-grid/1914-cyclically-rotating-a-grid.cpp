class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n = grid[0].size();
        int num_layers = min(m, n) / 2;
        
        // Process each concentric layer one by one
        for (int layer = 0; layer < num_layers; ++layer) {
            int top = layer;
            int bottom = m - 1 - layer;
            int left = layer;
            int right = n - 1 - layer;
            
            vector<int> unrolled;
            
            // 1. UNROLL: Read the layer in a clockwise direction
            // Top edge (left to right)
            for (int j = left; j <= right; ++j) unrolled.push_back(grid[top][j]);
            // Right edge (top to bottom)
            for (int i = top + 1; i <= bottom; ++i) unrolled.push_back(grid[i][right]);
            // Bottom edge (right to left)
            for (int j = right - 1; j >= left; --j) unrolled.push_back(grid[bottom][j]);
            // Left edge (bottom to top)
            for (int i = bottom - 1; i > top; --i) unrolled.push_back(grid[i][left]);
            
            // 2. SHIFT: Calculate the effective rotations needed
            int L = unrolled.size();
            int effective_k = k % L;
            
            // std::rotate shifts elements to the left, which perfectly mimics 
            // a counter-clockwise rotation for our clockwise unrolled array
            rotate(unrolled.begin(), unrolled.begin() + effective_k, unrolled.end());
            
            // 3. REROLL: Write the shifted array back into the matrix
            int idx = 0;
            
            // Top edge
            for (int j = left; j <= right; ++j) grid[top][j] = unrolled[idx++];
            // Right edge
            for (int i = top + 1; i <= bottom; ++i) grid[i][right] = unrolled[idx++];
            // Bottom edge
            for (int j = right - 1; j >= left; --j) grid[bottom][j] = unrolled[idx++];
            // Left edge
            for (int i = bottom - 1; i > top; --i) grid[i][left] = unrolled[idx++];
        }
        
        return grid;
        
    }
};