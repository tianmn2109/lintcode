class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        if (nums.size() == 1)
            return nums[0];
        int maxElement = nums[0];
        int count = 1;
        for (int i = 0; i < nums.size(); i ++) {
            if (maxElement == nums[i]) {
                count ++;
            }
            else if (count == 1) {
                maxElement = nums[i];
            }
            else {
                count --;
            }
        }
        return maxElement;
    }
};
