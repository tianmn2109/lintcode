class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if (n <= 2)
            return n;
        int a = 2;
        int b = 1;
        for (int i = 3; i <= n; i ++) {
            int temp = a;
            a = a + b;
            b = temp;
        }
        return a;
    }
};

