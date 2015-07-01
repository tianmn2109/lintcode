class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {
            int left = start;
            int right = end;
            int temp = nums[left];
            while (left < right) {
                while (left < right && nums[right] <= temp)                   // 注意这两处至少有一个必须为等于,否则会死循环， 2， ，2 ，2 ， 2
                    right --;
                if (left < right)
                    nums[left] = nums[right];
                while (left < right && nums[left] >= temp)                   // 注意此处必须是大于等于
                    left ++;
                if (left < right)
                    nums[right] = nums[left];
            }
            nums[left] = temp;
            if (k == left - start  + 1)
                return nums[left];
            if (left - start + 1 > k) {
                end = left - 1;
            }
            else {
                k = k - left + start - 1;
                start = left + 1;
            }
        }
        return nums[start];
    }
};

