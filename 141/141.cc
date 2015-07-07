class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        int left = 1;
        int right = x / 2;
        while (left <= right) {
            long long mid = (left + right) / 2;        // long long to avoid overflow
            if (mid * mid == x)
                return mid;
            if (mid * mid > x)
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return right;
    }
};

