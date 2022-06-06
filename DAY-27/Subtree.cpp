class Solution {
public:
    bool issametree(TreeNode* s,TreeNode* t)
    {
        if(s==NULL && t==NULL)
            return true;
        if(s==NULL || t==NULL || s->val!=t->val)
            return false;
       
        bool l=issametree(s->left,t->left);
        bool r=issametree(s->right,t->right);
        return l&&r;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL)
            return true;
        if(root==NULL || subRoot==NULL)
            return false;
        if(issametree(root,subRoot))
        {
            return true;
        }
       
            bool l=isSubtree(root->left,subRoot);
            bool r=isSubtree(root->right,subRoot);
        return l||r;
       
      
        
    }
};
