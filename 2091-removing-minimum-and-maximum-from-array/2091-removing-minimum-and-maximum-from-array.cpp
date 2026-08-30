#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int minimumDeletions(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; // If 1 or 2 elements, we have to delete everything

        // 1. Find the original indices of the minimum and maximum elements
        auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
        int min_idx = std::distance(nums.begin(), min_it);
        int max_idx = std::distance(nums.begin(), max_it);

        // Make sure min_idx is always the smaller index for easier math
        int i = std::min(min_idx, max_idx);
        int j = std::max(min_idx, max_idx);

        // 2. Calculate the 3 possible ways to remove both elements:
        // Option A: Delete both from the front
        int del_front = j + 1; 
        
        // Option B: Delete both from the back
        int del_back = n - i;  
        
        // Option C: Delete small index from front, large index from back
        int del_both = (i + 1) + (n - j); 

        // Return the minimum of the three options
        return std::min({del_front, del_back, del_both});
    }
};