class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        int maxS = nums[0];
        int minS = nums[0];
        int maxRet = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            int tempMax = max(nums[i], max(maxS * nums[i], minS * nums[i]));
            int tempMin = min(nums[i], min(maxS * nums[i], minS * nums[i]));
            maxS = tempMax;
            minS = tempMin;
            maxRet = max(maxRet, maxS);
        }
        return maxRet;
    }
};

