class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        vector<vector<int> > ret;
        if (nums.size() < 4)
            return ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i ++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size() - 2; j ++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[left]);
                        v.push_back(nums[right]);
                        ret.push_back(v);
                    }
                    if (sum - target > 0) {
                        right --;
                        while (left < right && nums[right] == nums[right + 1])
                            right --;
                    }
                    else {
                        left ++;
                        while (left < right && nums[left] == nums[left - 1])
                            left ++;
                    }
                }
            }
        }
        return ret;
    }
};


