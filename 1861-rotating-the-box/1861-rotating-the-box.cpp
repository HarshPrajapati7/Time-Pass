#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        
        // Step 1: Apply "gravity" to the right in the original box
        for (int i = 0; i < m; ++i) {
            // Track the furthest right empty position
            int empty_spot = n - 1; 
            
            // Scan from right to left
            for (int j = n - 1; j >= 0; --j) {
                if (boxGrid[i][j] == '*') {
                    // Obstacle blocks falling; next empty spot is right behind it
                    empty_spot = j - 1;
                } 
                else if (boxGrid[i][j] == '#') {
                    // Stone found! Move it to the empty spot
                    boxGrid[i][j] = '.';
                    boxGrid[i][empty_spot] = '#';
                    // The empty spot moves one step left
                    empty_spot--;
                }
            }
        }
        
        // Step 2: Create the rotated grid (n x m)
        vector<vector<char>> rotated(n, vector<char>(m));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Standard 90-degree clockwise rotation formula
                rotated[j][m - 1 - i] = boxGrid[i][j];
            }
        }
        
        return rotated;
    }
};