class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if (nums.size() <= 1)
            return nums.size();
        int k = 0;
        for (int i = 1; i < nums.size(); i ++)
            if (nums[k] != nums[i])
                nums[++ k] = nums[i];
        return k + 1;
    }
};
