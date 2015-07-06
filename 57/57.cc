class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        vector<vector<int> > ret;
        if (nums.size() < 3)
            return ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i ++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[left]);
                    v.push_back(nums[right]);
                    ret.push_back(v);
                }
                if (sum > 0) {
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


