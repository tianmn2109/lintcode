class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i ++)
            if (obstacleGrid[i][0] == 1)
                break;
            else
                dp[i][0] = 1;
        for (int i = 0; i < n; i ++)
            if (obstacleGrid[0][i] == 1)
                break;
            else
                dp[0][i] = 1;
        for (int i = 1; i < m; i ++)
            for (int j =1; j < n; j ++)
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j -1];
        return dp[m - 1][n -1];
    }
};

