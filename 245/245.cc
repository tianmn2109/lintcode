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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        if (T2 == NULL)         // 顺序不能倒
            return true;
        if (T1 == NULL)
            return false;       // 顺序不能倒
        if (T1->val == T2->val && aux(T1, T2))
            return true;
        if (isSubtree(T1->left, T2))
            return true;
        if (isSubtree(T1->right, T2))
            return true;
        return false;
    }
    bool aux(TreeNode *T1, TreeNode *T2) {
        if (T1 == NULL && T2 == NULL)
            return true;
        if (T1 != NULL && T2 != NULL && T1->val == T2->val)
            return aux(T1->left, T2->left) && aux(T1->right, T2->right);
        return false;
    }
};
