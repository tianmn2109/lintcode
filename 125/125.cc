class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        vector<vector<int> > dp(A.size() + 1,vector<int>(m + 1, 0));

        for (int i = 0;i < A.size(); i ++) {
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        for (int i = 1; i <= A.size(); i ++) {
            for (int j = 1; j <= m; j ++) {
                if (j - A[i -1] < 0)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i - 1]] + V[i - 1]);
            }
        }
        return dp[A.size()][m];
    }
};

