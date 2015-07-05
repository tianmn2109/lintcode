class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if (source == NULL || target == NULL)
            return -1;
        if (*target == '\0')
            return 0;
        int lenSource = 0;
        int lenTarget = 0;
        while (*(source + lenSource) != '\0')
            lenSource ++;
        while (*(target + lenTarget) != '\0')
            lenTarget ++;
        if (lenSource < lenTarget)
            return -1;
        for (int i = 0; i < lenSource; i ++) {
            int j = 0;
            for (; j < lenTarget; j ++) {
                if (*(source + i + j) != *(target + j))
                    break;
            }
            if (j == lenTarget)
                    return i;
        }
        return -1;
    }
};


