/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
     
     vector<TreeNode *> generateT(int left, int right) {
        vector<TreeNode *> ret;
        if (left > right) {
            ret.push_back(NULL);
            return ret;
        }
        for (int k = left; k<= right; k ++) {
            vector<TreeNode *> lchild = generateT(left, k - 1);
            vector<TreeNode *> rchild = generateT(k + 1, right);
            for (int i = 0; i < lchild.size(); i ++)
                for (int j = 0; j < rchild.size(); j ++) {
                    TreeNode *root = new TreeNode(k);            
                    root->left = lchild[i];
                    root->right = rchild[j];
                    ret.push_back(root);
                }
        }
        return ret;
     }
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        return generateT(1, n);
    }
};

