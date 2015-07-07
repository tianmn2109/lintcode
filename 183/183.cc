#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    bool canSplit(vector<int> L, int k, int len) {
        long long cnt = 0;
        for (int i = 0; i < L.size(); i ++) {
            cnt += L[i] / len;
        }
        return cnt >= k;
    }
    int woodCut(vector<int> L, int k) {
        // write your code here
        long long sum = 0;
        for (int i = 0; i < L.size(); i ++)
            sum += L[i];
        if (sum < k)
            return 0;
        long long left = 1;
        long long right = *max_element(L.begin(), L.end());
        while (left < right) {
            long long mid = (left + right + 1) / 2;                  // 避免死循环 如果不加1 当left 114 right 115 时  死循环
            if (canSplit(L, k, mid))
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};

int main()
{
	vector<int> v;
	v.push_back(232);
	v.push_back(124);
	v.push_back(456);
	Solution s;
	cout << s.woodCut(v, 7) << endl;
	return 0;
}
