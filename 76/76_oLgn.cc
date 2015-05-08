#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int binarySearch(vector<int> &a, int left, int right, int target) {
            while (left <= right) {
                int middle = (left + right) / 2;
                if (a[middle] == target)
                {
                    while (a[++middle] > target)
                        return middle;
                }
                if (a[middle] < target)
                    left = middle + 1;
                else
                    right = middle - 1;
            }
            if (right >= 0 && right < left)
                left = right;
            while (a[left] <= target)
                left ++;
            return left;
    }
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        if (nums.size() == 0)
            return 0;
        vector<int> m(nums.size(), 1);
        m[0] = nums[0];
        int maxlen = 1;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] >= m[maxlen - 1])
                m[maxlen ++] = nums[i];
            else {
                int p = binarySearch(m, 0, maxlen - 1, nums[i]);
                m[p] = nums[i];
            }
        }
        return maxlen;

    }
};

int main()
{
	vector<int> nums;
	nums.push_back(9);
	nums.push_back(3);
	nums.push_back(6);
	nums.push_back(2);
	nums.push_back(7);
	Solution s;
	cout  << s.longestIncreasingSubsequence(nums) << endl;
	return 0;
}
