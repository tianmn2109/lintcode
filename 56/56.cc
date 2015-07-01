class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        unordered_map<int, int> m;
        vector<int> ret;
        for (int i = 0; i < nums.size(); i ++) {
            if (m.find(target - nums[i]) != m.end()) {
                ret.push_back(m[target - nums[i]] + 1);
                ret.push_back(i + 1);
                break;
            }
            else {
                m[nums[i]] = i;
            }
        }
        return ret;
    }
};


