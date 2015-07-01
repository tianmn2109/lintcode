#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

 
 
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > ret;
        queue<TreeNode *> q;
        if (root == NULL)
            return ret;
        q.push(root);
        while (!q.empty()) {
            vector<int> v;
		int len = q.size();
            for (int i = 0; i < len(); i ++) {
                TreeNode *temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
            }
            ret.push_back(v);
        }
        return ret;
    }
};

int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *left = new TreeNode(2);
	TreeNode *right = new TreeNode(3);
	root->left = left;
	root->right = right;
	Solution s;
	s.levelOrder(root);
	return 0;

}
