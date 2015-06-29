class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int left = 0;
        int right = nums.size();
        while (left < right) {
            while (left < right && nums[left] % 2 == 1)
                left ++;
            if (left >= right)
                break;
            while (right > left && nums[right] % 2 == 0)
                right --;
            if (left < right) {
                swap(nums[left ++], nums[right --]);
            }
        }
    }
};

