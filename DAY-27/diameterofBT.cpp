/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diausingh(TreeNode* root,int &d){
        if(root==NULL){
            return 0;
        }
        int lh=diausingh(root->left,d);
        int rh=diausingh(root->right,d);
        d=max(d,lh+rh);
        return 1+max(lh,rh);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        diausingh(root,diameter);
        return diameter;
        
    }
};
