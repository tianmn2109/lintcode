class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        int k = (nums.size() - 1) / 2 + 1; // 中位数
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int left = start;
            int right = end;
            int temp = nums[left];
            while (left < right) {
                while (left < right && nums[right] >= temp)
                    right --;
                if (left < right)
                    nums[left] = nums[right];
                while (left < right && nums[left] < temp)
                    left ++;
                if (left < right)
                    nums[right] = nums[left];
            }
            nums[left] = temp;
            int tempK = left - start + 1;
            if (tempK == k)
                return nums[start + k - 1];
            else if (tempK > k) {
                end = left - 1;
            }
            else {
                start = left + 1;
                k = k - tempK;
            }
        }
    }
};
