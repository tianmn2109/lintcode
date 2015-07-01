class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        // write your code here
        if (k == 0)
            return 0;
        vector<long long> num(k  + 1);
        int index3 = 0;
        int index5 = 0;
        int index7 = 0;
        long n3 = 3;
        long n5 = 5;
        long n7 = 7;
        num[0] = 1;
        for (int i = 1; i < num.size(); i ++) {
            long long next = min(n3, min(n5, n7));
            num[i] = next;
            if (next == n3) {
                index3 ++;
                n3 = num[index3] * 3;
            }
            if (next == n5) {
                index5 ++;
                n5 = num[index5] * 5;
            }
            if (next == n7) {
                index7 ++;
                n7 = num[index7] * 7;
            }
        }
        return num[k];
    }
};

