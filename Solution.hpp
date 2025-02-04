#include <vector>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        // Initialize variables to keep track of the maximum ascending sum
        // and the current sum of the ongoing ascending subsequence.
        int max_Ascending_Sum = 0, current_Ascending_Sum = 0;
        
        // Iterate through each element in the vector
        for(int currentIndex = 0; currentIndex < nums.size(); ++currentIndex) {
            // Add the current element to the current ascending sum
            current_Ascending_Sum += nums[currentIndex];
            
            // Check if we are at the last element or if the next element is not greater
            // than the current one (sequence no longer ascending)
            if(currentIndex + 1 >= nums.size() || nums[currentIndex] >= nums[currentIndex + 1]) {
                // Update the maximum ascending sum if the current ascending sum is greater
                max_Ascending_Sum = max(max_Ascending_Sum, current_Ascending_Sum);
                
                // Reset the current ascending sum to 0 for the next potential sequence
                current_Ascending_Sum = 0;
            }
        }

        // Return the largest ascending subsequence sum found
        return max_Ascending_Sum;
    }
};