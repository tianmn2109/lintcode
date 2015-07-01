Method 2: Analytical solution.

Every time, calculate how many k has appears on a specific postion, i.e., on 1, 10, 100,.....
class Solution {
    /*
     * param k : As description.
     * param n : As description.
     * return: An integer denote the count of digit k in 1..n
     */
    public int digitCounts(int k, int n) {
        int res = 0;
        int base = 1;
        while (base<=n){
            int part1 = n/(base*10);
            if (base>1 && k==0 && part1>0) part1--;
            part1 *= base;
            int bar = n/base%10;
            int part2 = 0;
            if (k<bar) part2 = base;
            else if (k==bar) part2 = n%base+1;
            if (k==0 && n<base*10) part2 = 0;
            res += part1+part2;
            base*=10;
        }
        return res;    
    }
};
