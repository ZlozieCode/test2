class Solution {
public:
// Time Complexity: O(n^2) - Nested loop
// Space Complexity: O(1) - Constant extra space
vector<int> twoSum(vector<int>& nums, int target) {
    // Loop through each element in the array
    for (int i = 0; i < nums.size(); ++i) {
        // For each element, loop through the rest of the array
        for (int j = i + 1; j < nums.size(); ++j) {
            // Check if the sum of current pair equals the target
            if (nums[i] + nums[j] == target) {
                // Return the indices if found
                return {i, j};
            }
        }
    }
    return {}; // Return empty vector if no solution found
}
};