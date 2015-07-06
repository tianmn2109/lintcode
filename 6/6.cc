class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        int lenA = A.size();
        int lenB = B.size();
        int i = 0;
        int j = 0;
        vector<int> ret;
        while (i < lenA && j < lenB) {
            if (A[i] < B[j])
                ret.push_back(A[i ++]);
            else 
                ret.push_back(B[j ++]);
        }
        while (i < lenA)
            ret.push_back(A[i ++]);
        while (j < lenB)
            ret.push_back(B[j ++]);
            return ret;
    }
};

