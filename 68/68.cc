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
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        stack<TreeNode *> stk;
        TreeNode *prev = NULL;
        TreeNode *cur = NULL;
        vector<int> ret;
        if (root != NULL)
            stk.push(root);
        while (!stk.empty()) {
            cur = stk.top();
            if ((cur->left == NULL && cur->right == NULL) 
                || (prev != NULL && (cur->left == prev || cur->right == prev))) {
                    stk.pop();
                    ret.push_back(cur->val);
                    prev = cur;
            }
            else {
                if (cur->right != NULL) {
                    stk.push(cur->right);
                }
                if (cur->left != NULL) {
                    stk.push(cur->left);
                }
            }
        }
        return ret;
    }
};

