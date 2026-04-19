class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0; // Pointer for nums1
        int j = 0; // Pointer for nums2
        int max_dist = 0;

        int n = nums1.size();
        int m = nums2.size();

        while (i < n && j < m) {
            // If the condition is met, calculate distance and try to expand j
            if (nums1[i] <= nums2[j]) {
                max_dist = max(max_dist, j - i);
                j++; 
            } 
            // If nums1[i] is too big, move i to a smaller element
            else {
                i++;
            }
        }

        return max_dist;
    }
};