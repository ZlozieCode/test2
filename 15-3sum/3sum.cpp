class Solution {
public:

// Time Complexity: O(n^2) - Nested loops
// Space Complexity: O(1) - Constant extra space
vector<vector<int>> threeSum(vector<int>& nums) {
    // Sort the input array
    sort(nums.begin(), nums.end());
    // Initialize a vector to store the result
    vector<vector<int>> res;
    // Loop through the array up to the third last element
    for (int i = 0; i < nums.size() - 2; ++i) {
        // Skip duplicates
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        // Initialize two pointers, one at i+1 and the other at the end of the array
        int l = i + 1, r = nums.size() - 1;
        // Two-pointer technique to find pairs that sum up to the target
        while (l < r) {
            // Calculate the sum of the current triplet
            int sum = nums[i] + nums[l] + nums[r];
            // If the sum is less than zero, move the left pointer to the right
            if (sum < 0) {
                ++l;
            }
            // If the sum is greater than zero, move the right pointer to the left
            else if (sum > 0) {
                --r;
            }
            // If the sum is zero, add the triplet to the result
            else {
                res.push_back({nums[i], nums[l], nums[r]});
                // Skip duplicates
                while (l < r && nums[l] == nums[l + 1]) ++l;
                while (l < r && nums[r] == nums[r - 1]) --r;
                // Move both pointers to the next distinct elements
                ++l;
                --r;
            }
        }
    }
    // Return the result vector
    return res;
}

};