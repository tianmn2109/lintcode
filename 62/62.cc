class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        int left = 0;
        int right = A.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] == target)
                return mid;
            if (A[mid] > A[right]) {
                if (A[left] <= target && target < A[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else {
                if (A[mid] < target && target <= A[right])
                    left = mid + 1;
                else 
                    right = mid - 1;
            }
        }
        return -1;
    }
};

