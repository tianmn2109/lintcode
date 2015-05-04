class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        int len = word2.size();
        vector<vector<int> > d(2, vector<int>(len + 1));
        for (int i = 0; i <= len; i ++)
            d[0][i] = i;                                                // very important
        for (int i = 1; i <= word1.size(); i ++) {
            d[i&1][0] = i;
            for (int j = 1; j <= len; j ++) {
                if (word1[i - 1] == word2[j - 1])
                    d[i&1][j] = d[(i - 1)&1][j - 1];
                else {
                    d[i&1][j] = min(d[i&1][j - 1], min(d[(i-1)&1][j], d[(i-1)&1][j-1])) + 1;
                }
            }
        }
        return d[word1.size()&1][word2.size()];
    }
};


