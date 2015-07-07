class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &A) {
        // write your code here
        int left = 0;
        int right = A.size() - 1;
        while (left < right) {
            if (A[left] < A[right])
                return A[left];
            int mid = (left + right) / 2;
            if (A[mid] > A[right]) {
                left = mid + 1;
            }
            else if (A[mid] < A[right]) {
                right = mid;
            }
            else {
                right --;
            }
        }
        return A[left];
    }
};

