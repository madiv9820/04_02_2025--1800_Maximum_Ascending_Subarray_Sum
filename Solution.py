from typing import List

class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        max_Ascending_Sum = 0
        n = len(nums)

        for i in range(n):
            current_Ascending_Sum = nums[i]
            
            for j in range(i+1, n):
                if nums[j] > nums[j-1]: current_Ascending_Sum += nums[j]
                else: break
            
            max_Ascending_Sum = max(max_Ascending_Sum, current_Ascending_Sum)

        return max_Ascending_Sum