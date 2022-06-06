class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isSymmetrictest(root->left,root->right);
    }
    bool isSymmetrictest(TreeNode* p,TreeNode* q)
    {
        if(p==NULL && q==NULL)
            return true;
        if(p==NULL || q==NULL)
            return false;
        if(p->val!=q->val)
            return false;
        return isSymmetrictest(p->left,q->right)&& isSymmetrictest(p->right,q->left);
        
    }
};
