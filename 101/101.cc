class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if (nums.size() <= 2)
            return nums.size();
        int k = 1;
        for (int i = 2; i < nums.size(); i ++) {
            if (nums[i] != nums[k] || nums[i] != nums[k - 1])
                nums[++ k] = nums[i];
        }
        return k + 1;
    }
};
