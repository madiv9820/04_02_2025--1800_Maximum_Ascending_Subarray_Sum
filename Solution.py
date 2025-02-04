from typing import List

class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        # Initialize the variable to store the maximum sum found so far
        max_Ascending_Sum = 0
        
        # Get the length of the input list
        n = len(nums)

        # Outer loop: Iterate through each element in the list
        for i in range(n):
            # Initialize the current ascending sum to be the value of the current element
            current_Ascending_Sum = nums[i]
            
            # Inner loop: Check subsequent elements to see if they form an ascending sequence
            for j in range(i+1, n):
                # If the current element is greater than the previous one, continue the ascending sum
                if nums[j] > nums[j-1]: current_Ascending_Sum += nums[j]
                # If the sequence is no longer ascending, break out of the inner loop
                else: break
            
            # Update the maximum ascending sum if the current ascending sum is greater
            max_Ascending_Sum = max(max_Ascending_Sum, current_Ascending_Sum)

        # Return the maximum ascending sum found
        return max_Ascending_Sum