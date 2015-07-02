class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        long long ret;
        int i = 0;
        int len = str.size();
        while (i < len && str[i] == ' ')
            i ++;
        bool isNegative = false;
        if (str[i] == '+' || str[i] == '-') {
            if (str[i] == '-')
                isNegative = true;
            i ++;
        }
        while (i < len) {
            if (isdigit(str[i])) {
                ret = ret * 10 + str[i] - '0';
                if (ret > 0x7FFFFFFFL + 1)
                    break;
            }
            else if (str[i] == ' ') {
                
            }
            else {
                //ret = 0;
                break;
            }
            i ++;
        }
        if (!isNegative && ret > INT_MAX)
            ret = INT_MAX;
        if (isNegative && ret > 0x7FFFFFFFL + 1)
            ret = 0x7FFFFFFFL + 1;
        return isNegative ? -ret : ret;
    }
};
