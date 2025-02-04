#include <vector>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_Ascending_Sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; ++i) {
            int current_Ascending_Sum = nums[i];
            
            for(int j = i+1; j < n; ++j) {
                if(nums[j] > nums[j-1]) current_Ascending_Sum += nums[j];
                else break;
            }

            max_Ascending_Sum = max(max_Ascending_Sum, current_Ascending_Sum);
        }

        return max_Ascending_Sum;
    }
};