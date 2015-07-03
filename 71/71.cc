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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > ret;
        queue<TreeNode *> q;
        stack<TreeNode *> stk;
        int curLevel = 1;
        if (root != NULL) 
            q.push(root);
        while (!q.empty()) {
            int len = q.size();
            vector<int> v;
            for (int i = 0; i < len; i ++) {
                TreeNode *cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if (curLevel % 2 == 0) {
                    if (cur->right != NULL)
                        stk.push(cur->right);
                    if (cur->left != NULL)
                        stk.push(cur->left);
                }
                else {
                    if (cur->left != NULL)
                        stk.push(cur->left);
                    if (cur->right != NULL)
                        stk.push(cur->right);
                }
            }
            ret.push_back(v);
            curLevel ++;
            while (!stk.empty()) {
                q.push(stk.top());
                stk.pop();
            }
        }
        return ret;
    }
};

