class Solution {
public:

// Time Complexity: O(n) - Single pass
// Space Complexity: O(1) - Constant extra space
vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size() - 1; // Initialize two pointers at the beginning and end of the sorted array
    while (l < r) { // While the two pointers haven't crossed each other
        int sum = numbers[l] + numbers[r]; // Calculate the sum of the current pair
        if (sum == target) { // If the sum equals the target
            return {l + 1, r + 1}; // Return the indices (1-based indexing)
        } else if (sum < target) { // If the sum is less than the target
            ++l; // Move the left pointer to the right to increase the sum
        } else { // If the sum is greater than the target
            --r; // Move the right pointer to the left to decrease the sum
        }
    }
    return {}; // Return an empty vector if no solution is found
}

};