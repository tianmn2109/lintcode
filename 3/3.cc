class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int count = 0;
        if (k == 0)
            count ++;
        for (int i = 1; i <= n; i ++) {
            int x = i;
            while (x) {
                if (k == x%10) {
                    count ++;
                }
                x /= 10;
            }
        }
        return count;
    }
};

