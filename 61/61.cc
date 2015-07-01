class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> ret(2, -1);
        int left = 0;
        int right = A.size() - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (A[middle] == target) {
                int start = middle;
                int end = start;
                while (start > left && A[start - 1] == target)
                    start --;
                while (end < right && A[end + 1] == target)
                    end ++;
                ret[0] = start;
                ret[1] = end;
                break;
            }
            if (A[middle] > target) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }
        return ret;
    }
};
