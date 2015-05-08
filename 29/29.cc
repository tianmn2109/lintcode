class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        if (s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<int> > v(s1.size() + 1, vector<int>(s2.size() + 1, false));
        if (s3.size() == 0)
            v[0][0] = true;
        for (int i = 0; i < s1.size(); i ++)
        {
            if (s1[i] == s3[i])
                v[i + 1][0] = true;
            else
                break;
        }
        for (int i = 0; i < s2.size(); i ++)
        {
            if (s2[i] == s3[i])
                v[0][i + 1] = true;
            else
                break;
        }
        for (int i = 1; i <= s1.size(); i ++)
            for (int j = 1; j <= s2.size(); j ++)
            {
                if (s1[i - 1] == s3[i + j - 1])
                    v[i][j] |= v[i - 1][j];
                if (s2[j - 1] == s3[i + j - 1])
                    v[i][j] |= v[i][j  -1];
            }
        return v[s1.size()][s2.size()];
    }
};

