class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        int closest = INT_MAX;
        int ret = 0;
        if (nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i ++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < closest) {
                    ret = sum;
                    closest = abs(sum - target);
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
        return ret;
    }
};


