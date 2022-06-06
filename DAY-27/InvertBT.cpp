class Solution {
public:
    void invert(TreeNode* root)
    {
        if(root==NULL)
            return;
         invert(root->left);
        invert(root->right);
        TreeNode* r1=root->right;
        root->right=root->left;
        root->left=r1;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
       invert(root);
        return root;
        
    }
};
