class Solution {
public:
    void fill(TreeNode* root,vector<string>&ans,string str)
    {
        if(root==NULL){
           
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            str+=to_string(root->val);
            ans.push_back(str);
            return;
        }
        str+=to_string(root->val);
        if(root->left||root->right)
            str+="->";
        fill(root->left,ans,str);
        fill(root->right,ans,str);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(!root)return ans;
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(to_string(root->val));
            return ans;
        }
        string str=to_string(root->val);
        str+="->";
        fill(root->left,ans,str);
        fill(root->right,ans,str);
        return ans;
        
    }
};
