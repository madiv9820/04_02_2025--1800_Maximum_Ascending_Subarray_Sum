from typing import List

class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        # Initialize variables to track the maximum sum and the current ascending sum
        max_Ascending_Sum = current_Ascending_Sum = 0
        
        # Get the length of the input list
        n = len(nums)

        # Iterate over each element in the list
        for currentIndex in range(n):
            # Add the current element to the current ascending sum
            current_Ascending_Sum += nums[currentIndex]
            
            # Check if the current element is the last in the list or if the sequence is no longer ascending
            if currentIndex + 1 >= n or nums[currentIndex] >= nums[currentIndex + 1]:
                # Update the maximum ascending sum if the current ascending sum is greater
                max_Ascending_Sum = max(max_Ascending_Sum, current_Ascending_Sum)
                # Reset the current ascending sum for the next possible sequence
                current_Ascending_Sum = 0
        
        # Return the maximum ascending sum found
        return max_Ascending_Sum