class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        int left = 1;
        int right = A.size() - 2;
        while (left < right) {
            int mid = (left + right) / 2;
            if (A[mid] > A[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};


