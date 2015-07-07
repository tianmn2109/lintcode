class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int top = 0;
        int bottom = matrix.size() - 1;
        while (top <= bottom) {
            int mid = (top + bottom) / 2;
            if (matrix[mid][0] == target)
                return true;
            if (matrix[mid][0] > target)
                bottom = mid - 1;
            else
                top = mid + 1;
        }
        int left = 0;
        int right = matrix[bottom].size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[bottom][mid] == target)
                return true;
            if (matrix[bottom][mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};


