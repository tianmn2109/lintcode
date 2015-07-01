class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int b = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            if (b > 0)
                b = b + nums[i];
            else 
                b = nums[i];
            maxSum = max(maxSum, b);
        }
        return maxSum;
    }
};

