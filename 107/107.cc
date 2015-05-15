class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordSegmentation(string s, unordered_set<string> &dict) {
        // write your code here
        vector<bool> dp(s.size() + 1, false);
        int maxLen = 0; //to get the max length word
        for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it ++) {
            maxLen = max(maxLen, (int)(*it).size());
        }
    
        dp[0] = true;
        for (int i = 1; i <= s.size(); i ++) {
            for (int j  = max(i - maxLen,0); j < i; j ++) {    // j start from the max len word , if not , the last two case will exceed limited time.
                if (!dp[j])
                    continue;
                if (dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

