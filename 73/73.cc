class Solution {
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        return buildAux(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode *buildAux(vector<int> &preorder, int leftPre, int rightPre, vector<int> &inorder, int leftIn, int rightIn) {
        if (leftPre > rightPre || leftIn > rightIn)
            return NULL;
        TreeNode *node = new TreeNode(preorder[leftPre]);
        int i = 0;
        for (i =  leftIn; i <= rightIn; i ++)
            if (inorder[i] == preorder[leftPre])
                break;
        int leftNum = i - leftIn;
        int rightNum = rightIn - i;
        node->left = buildAux(preorder, leftPre + 1, leftPre + leftNum, inorder, leftIn, i - 1);
        node->right = buildAux(preorder, leftPre + leftNum + 1, rightPre, inorder, i + 1, rightIn);
        return node;
    }
};

