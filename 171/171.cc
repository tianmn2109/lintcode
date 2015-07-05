class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        map<string, int> m;
        vector<string> ret;
        for (int i = 0; i < strs.size(); i ++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (m.find(str) == m.end()) {
                m[str] = i;
            }
            else {
                if (m[str] != -1) {
                    ret.push_back(strs[m[str]]);
                    m[str] = -1;
                }
                ret.push_back(strs[i]);
            }
        }
        return ret;
    }
};
