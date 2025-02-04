# 1800. Maximum Ascending Subarray Sum (All Approaches)
- ## Approach 1:- Brute Force
    - ### Intuition:
        The problem requires finding the maximum sum of an ascending subsequence in a given list of numbers. The subsequence should contain consecutive elements where each element is strictly greater than the one before it.

        - #### Key Observations:
            - The sum of an ascending subsequence can only be extended as long as each subsequent element is greater than the previous one.
            - Once an element is found that is not greater than the previous one, the current subsequence ends.
            - By iterating through the array and checking each possible subsequence, we can find the one with the largest sum.

    - ### Approach:
        1. **Initialization**:
            - Start by initializing a variable `max_Ascending_Sum` to keep track of the maximum sum found during the process.
        
        2. **Iterate Over the List**:
            - For each element in the list, treat it as the starting point of an ascending subsequence.
            - Initialize the `current_Ascending_Sum` to be the value of the starting element.

        3. **Check Ascending Sequence**:
            - Use a nested loop to check the next elements in the list.
            - If the next element is greater than the previous one, add it to the `current_Ascending_Sum`.
            - If an element is found that is not greater than the previous one, break the inner loop.

        4. **Update Maximum Sum**:
            - After each subsequence is checked, compare the `current_Ascending_Sum` with the `max_Ascending_Sum` and update it if the current sum is larger.

        5. **Return the Result**:
            - After all elements have been processed, return the `max_Ascending_Sum`, which holds the largest sum found.

    - ### Code Implementation:
        - **Python Solution**
            ```python3 []
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
            ```
        - **C++ Solution**
            ```cpp []
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
            ```

    - ### Time Complexity:
        - The time complexity of this approach is **$O(n^2)$**, where `n` is the length of the input list. This is because for each element, we may need to check subsequent elements in the list to form an ascending subsequence.
        - The outer loop runs `n` times, and the inner loop, in the worst case, could run `n-1`, `n-2`, ..., 1 times, leading to a total of approximately $(\frac{n\times(n-1)}{2})$, which simplifies to **$O(n^2)$**.

    - ### Space Complexity:
        - The space complexity is **$O(1)$** because we are only using a constant amount of extra space (for variables like `max_Ascending_Sum` and `current_Ascending_Sum`), regardless of the input size.
<hr>

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
<hr>