class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        vector<int> ret;
        priority_queue<int, vector<int>, greater<int> > maxHeap;
        priority_queue<int> minHeap;
        int median = nums[0];
        minHeap.push(median);
        ret.push_back(median);
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] < median) {
                minHeap.push(nums[i]);
            }
            else {
                maxHeap.push(nums[i]);
            }
            if (maxHeap.size() > minHeap.size()) {
                median = maxHeap.top();
                maxHeap.pop();
                minHeap.push(median);
            }
            else if (minHeap.size() > maxHeap.size() + 1) {
                maxHeap.push(median);
                minHeap.pop();
                median = minHeap.top();
            }
            ret.push_back(median);
        }
        return ret;
    }
};


