class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        int countSpace = 0;
        for (int i = 0; i < length; i ++)
            if (string[i] == ' ')
                countSpace ++;
        int newLength = length + 2 * countSpace;
        int k = newLength - 1;
        for (int i = length - 1; i >= 0; i --) {
            if (string[i] != ' ') {
                string[k --] = string[i];
            }
            else {
                string[k --] = '0';
                string[k --] = '2';
                string[k --] = '%';
            }
        }
        return newLength;
    }
};  

