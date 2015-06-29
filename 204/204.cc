class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution * s;
    static Solution* getInstance() {
        // write your code here
        if (s != NULL)
            return s;
        s = new Solution();
        return s;
    }
};
Solution * Solution::s = NULL;
