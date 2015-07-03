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
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    void getPath(vector<TreeNode *> v, vector<TreeNode *> &va, vector<TreeNode *> &vb,
                    TreeNode *cur, TreeNode *A, TreeNode *B) {
                        if (cur == NULL)
                            return ;
                        v.push_back(cur);
                        if (cur == A) {
                            va = v;
                //            return ;
                        }
                        if (cur == B) {
                            vb = v;
                //            return ;
                        }
                        getPath(v, va, vb, cur->left, A, B);
                        getPath(v, va, vb, cur->right, A, B);
                    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        vector<TreeNode *> v;
        vector<TreeNode *> va;
        vector<TreeNode *> vb;
        getPath(v, va, vb, root, A, B);
        TreeNode *ret = NULL;
        for (int i = 0; i < min(va.size(), vb.size()); i ++) {
            if (va[i] == vb[i]) {
                ret = va[i];
            }
            else {
                break;
            }
        }
        return ret;
    }
};

