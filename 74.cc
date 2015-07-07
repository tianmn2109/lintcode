/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        if (n <= 0) 
            return 0;
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            if (VersionControl::isBadVersion(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};


