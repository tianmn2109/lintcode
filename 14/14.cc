class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &A, int target) {
        // write your code here
        int left = 0;
        int right = A.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] == target) {
                int start = mid;
                while (start - 1 > 0 && A[start - 1] == target)
                    start --;
                return start;
            }
            if (A[mid] < target)
                left = mid + 1;
            else 
                right = mid - 1;
                
        }
        return -1;
    }
};

