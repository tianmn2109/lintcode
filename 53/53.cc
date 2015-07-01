class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        string ret = "";
        int pos = 0;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == ' ') {
                if (i > pos)
                    ret = s.substr(pos, i - pos) + " " + ret;
                pos = i + 1;
            }
            else if (i == s.size() - 1) {
                ret = s.substr(pos, s.size() - pos) + " " + ret;;
            }
        }
        return ret;
    }
};

