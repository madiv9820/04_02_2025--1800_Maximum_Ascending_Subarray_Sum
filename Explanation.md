- ## Approach 2:- Linear Scan
    - ### Intuition:
        The problem asks us to find the maximum sum of any strictly ascending subsequence in a given list of numbers. An ascending subsequence is defined as a sequence where each element is strictly greater than the one before it. The goal is to find the subsequence with the largest sum.

        - #### Key Observations:
            - The sum of an ascending subsequence can only be extended as long as the next element is strictly greater than the current one.
            - Whenever we encounter an element that is not greater than the previous element, the current subsequence ends, and we compare its sum to the maximum sum found so far.

    - ### Approach:
        1. **Initialization**:
            - Create two variables: `max_Ascending_Sum` to track the maximum ascending sum and `current_Ascending_Sum` to store the sum of the current ascending subsequence.

        2. **Iterate Over the List**:
            - For each element, add it to the `current_Ascending_Sum`.

        3. **Check Ascending Sequence**:
            - If we reach the last element or the current element is not smaller than the next element, we compare the `current_Ascending_Sum` with `max_Ascending_Sum` and update it if necessary.
            - After that, reset `current_Ascending_Sum` to 0 to start a new potential subsequence.

        4. **Return the Result**:
            - After iterating through the list, return the largest sum found in `max_Ascending_Sum`.

    - ### Code Implementation:
        - **Python Solution**
            ```python3 []
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
            ```
        - **C++ Solution**
            ```cpp []
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
            ```

    - ### Time Complexity:
        - The time complexity of the approach is **$O(n)$**, where `n` is the length of the input list. This is because we are iterating over the list exactly once, performing constant time operations at each step.

    - ### Space Complexity:
        - The space complexity is **$O(1)$**, since we only use a constant amount of extra space (for variables like `max_Ascending_Sum` and `current_Ascending_Sum`), regardless of the size of the input.