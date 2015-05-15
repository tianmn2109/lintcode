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
     * @param root: The root of binary tree.
     * @return: An integer
     */
     int maxValue;
     
     int maxP(TreeNode *root) {
         if (root == NULL)
            return 0;
         int a = maxP(root->left);
         int b = maxP(root->right);;
         maxValue = max(maxValue, a + b + root->val);
         maxValue = max(maxValue, a + root->val);
         maxValue = max(maxValue, b + root->val);
         maxValue = max(maxValue, root->val);
         return max(root->val, max(a + root->val, b + root->val));
     }
    int maxPathSum(TreeNode *root) {
        // write your code here
        maxValue = INT_MIN;
        maxP(root);
        return maxValue;
    }
};

