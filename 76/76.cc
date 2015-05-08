class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        if (nums.size() == 0)
            return 0;
        vector<int> v(nums.size(), 1);
        int maxlen = 1;
        for (int i = 1; i < nums.size(); i ++) {
            int tempMax = 0;
            for (int j = 0; j < i; j ++)
            {
                if (nums[j] <= nums[i] && v[j] > tempMax)
                    tempMax = v[j];
            }
            v[i] = tempMax + 1;
            if (v[i] > maxlen)
                maxlen = v[i];
        }
        return maxlen;

    }
};


