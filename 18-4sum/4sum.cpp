class Solution {
public:


// Time Complexity: O(n^3) - Triple nested loops, where n is the size of the input array.

// Space Complexity: O(1) - Constant extra space used except for the result vector.
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Check if input array size is less than 4
    if(nums.size() < 4) return {}; // If array size is less than 4, return empty vector
    
    sort(nums.begin(), nums.end()); // Sort the input array
    
    vector<vector<int>> res; // Initialize the result vector
    
    // Iterate through the array to find the first element for the quadruplet
    for (int i = 0; i < nums.size() - 3; ++i) {
        // Skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        // Iterate through the array to find the second element for the quadruplet
        for (int j = i + 1; j < nums.size() - 2; ++j) {
            // Skip duplicate values for the second element
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            
            int l = j + 1, r = nums.size() - 1; // Initialize left and right pointers
            
            // Use two pointers approach to find the remaining two elements
            while (l < r) {
                long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r]; // Calculate the sum
                
                // If sum equals target, add the quadruplet to the result
                if (sum == target) {
                    res.push_back({nums[i], nums[j], nums[l], nums[r]});
                    // Skip duplicate values for the third element
                    while (l < r && nums[l] == nums[l + 1]) ++l;
                    // Skip duplicate values for the fourth element
                    while (l < r && nums[r] == nums[r - 1]) --r;
                    ++l; // Move left pointer to the right
                    --r; // Move right pointer to the left
                } else if (sum < target) { // If sum is less than target, move left pointer to the right
                    ++l;
                } else { // If sum is greater than target, move right pointer to the left
                    --r;
                }
            }
        }
    }
    return res; // Return the result vector
}

};