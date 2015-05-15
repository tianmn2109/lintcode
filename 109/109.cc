class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        if (triangle.size() == 0)
            return 0;
        int n = triangle.size();
        vector<int> dp(n);
        for (int i = 0; i < n; i ++)
            dp[i] = triangle[n -1][i];
        for (int i = n - 2; i >= 0; i --)
            for (int j = 0; j <= i; j ++)
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        return dp[0];
    }
};


