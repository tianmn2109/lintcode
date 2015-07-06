class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        if (nums.size() == 0)
            return 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            while (left < right && nums[left] < k)
                left ++;
            if (left >= right)
                break;
            while (left < right && nums[right] >= k)                // 此处是大于等于
                right --;
            if (left < right) {
                swap(nums[left], nums[right]);
                left ++;
                right --;
            }
        }
        return nums[left] >= k ? left : left + 1;
    }
};

