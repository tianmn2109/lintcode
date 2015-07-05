class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string com(string &s1, string &s2) {
        string ret = "";
        for (int i = 0; i < min(s1.size(), s2.size()); i ++)
            if (s1[i] == s2[i])
                ret += s1[i];
            else
                break;
        return ret;
    }
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        string ret = "";
        if (strs.size() == 0)
            return ret;
        ret = strs[0];
        for (int i = 1; i < strs.size(); i ++)
            ret = com(ret, strs[i]);
        return ret;
    }
};
