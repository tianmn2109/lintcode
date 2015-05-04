class Solution {
public:
  /**
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    int gcd(int m, int n) {
        if (n > m)
            return gcd(n, m);
        while (n != 0) {
            int temp = n;
            n = m % n;
            m = temp;
        }
        return m;
    }
    string rotateString(string A, int offset) {
        // wirte your code here
        if (A.size() == 0 || A.size() == 1)
            return A;
        int off = offset % A.size();
        if (off == 0)
            return A;
        int d = gcd(A.size(), off);
        int shift = A.size() - off;
        for (int i = 0; i < d; i ++) {
            int prev = i;
            int temp = A[i];
            for (int j = (i + shift) % A.size(); j != i; j = (j + shift) % A.size()) {
                A[prev] = A[j];
                prev = j;
            }
            A[prev] = temp;
        }
        return A;
    }
};

