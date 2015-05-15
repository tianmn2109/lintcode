class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        vector<vector<int> > dp(k + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < A.size(); i ++) {
            for (int j = k; j > 0; j --) {
                for (int t = target; t >= A[i]; t --) {
                    dp[j][t] += dp[j - 1][t - A[i]];
                }
            }
        }
        return dp[k][target];
    }
};

