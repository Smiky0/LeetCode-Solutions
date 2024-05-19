#include <iostream>

using namespace std;

class Solution{

public:

    int leftHeight(TreeNode *node)
    {
        int height = 0;
        while(node!=NULL)
        {
            node = node->left;
            height ++;
        }
        return height;
    }

    int rightHeight(TreeNode *node)
    {
        int height = 0;
        while(node != NULL)
        {
            node = node->right;
            height ++;
        }
        return height;
    }


    int CountNodes(TreeNode *root)
    {
        // if root is empty
        if (root == NULL)
        {
            return 0;
        }
        // else
        int left_treeH =  leftHeight(root);
        int right_treeH = rightHeight(root);

        // if both side have same height
        if(left_treeH == right_treeH)
        {
            // use the formula to get node count
            return (1<<left_treeH)-1 ;	// 2^(height-1)
        }
        return 1 + CountNodes(root->left) + CountNodes(root->right);
    }
}