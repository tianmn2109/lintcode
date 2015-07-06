class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        for (int i = 0; i < A.size(); i ++) {
            if (A[i] > 0 && A[i] <= A.size() && A[i] != A[A[i] - 1]) {
                swap(A[i], A[A[i] - 1]);
                i --;
            }
        }
        int i = 0;
        for (i = 0; i < A.size(); i ++)
            if (A[i] != i + 1)
                break;
        return i + 1;
    }
};

