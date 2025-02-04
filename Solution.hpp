#include <vector>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        // Initialize the variable to store the maximum ascending sum found so far
        int max_Ascending_Sum = 0;
        
        // Get the size of the input vector
        int n = nums.size();

        // Outer loop: Iterate through each element in the vector
        for(int i = 0; i < n; ++i) {
            // Initialize the current ascending sum to be the value of the current element
            int current_Ascending_Sum = nums[i];
            
            // Inner loop: Check subsequent elements to see if they form an ascending sequence
            for(int j = i + 1; j < n; ++j) {
                // If the current element is greater than the previous one, continue adding to the sum
                if(nums[j] > nums[j - 1]) current_Ascending_Sum += nums[j];
                // If the sequence is no longer ascending, break out of the inner loop
                else break;
            }

            // Update the maximum ascending sum if the current ascending sum is greater
            max_Ascending_Sum = max(max_Ascending_Sum, current_Ascending_Sum);
        }

        // Return the maximum ascending sum found
        return max_Ascending_Sum;
    }
};