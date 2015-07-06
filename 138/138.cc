class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        unordered_map<int, int> m;
        m[0] = - 1;
        int sum = 0;
        vector<int> ret;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            if (m.find(sum) == m.end()) {
                m[sum] = i;
            }
            else {
                ret.push_back(m[sum] + 1);
                ret.push_back(i);
                break;
            }
        }
        return ret;
    }
};
