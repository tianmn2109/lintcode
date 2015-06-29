class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if (matrix.size() == 0)
            return 0;
        if (matrix[0].size() == 0)
            return 0;
        int count = 0;
        for (int i = 0; i < matrix.size() && target >= matrix[i][0]; i ++)
            if (binarySearch(matrix[i], target) != -1)
                count ++;
        return count;
    }
    int binarySearch(vector<int> v, int target) {
        int left = 0;
        int right = v.size();
        while (left <= right) {
            int middle = (left + right) / 2;
            if (v[middle] == target)
                return middle;
            if (v[middle] < target)
                left = middle + 1;
            else
                right = middle - 1;
        }
        return -1;
    }
};


