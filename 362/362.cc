class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        deque<int> d;
        vector<int> ret;
        for (int i = 0; i < k - 1; i ++) {
            while (!d.empty() && nums[d.back()] < nums[i])
                d.pop_back();
            d.push_back(i);
        }
        for (int i = k - 1; i < nums.size(); i ++) {
            while (!d.empty() && nums[d.back()] < nums[i])
                d.pop_back();
            while (!d.empty() && i - d.front() + 1 > k)
                d.pop_front();
            d.push_back(i);
            ret.push_back(nums[d.front()]);
        }
        return ret;
    }
};
