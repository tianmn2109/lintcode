class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        vector<int> ret;
        if (nums.size() <= 1) {
            ret.push_back(0);
            ret.push_back(0);
            return ret;
        }
        vector<pair<int, int> > v(nums.size() + 1);
        v[0].second = - 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            v[i + 1].first = sum;
            v[i + 1].second = i;
        }
        
        sort(v.begin(), v.end());
        int minDif = INT_MAX;
        int start = -1;
        int end = -1;
        for (int i = 1; i < v.size(); i ++) {
            if (v[i].first - v[i - 1].first < minDif) {
                minDif = v[i].first - v[i - 1].first;
                start = min(v[i].second + 1, v[i - 1].second + 1);
                end = max(v[i].second, v[i - 1].second);
            }
        }
        ret.push_back(start);
        ret.push_back(end);
        return ret;
    }
};


