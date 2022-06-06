class Solution {
public:
    TreeNode* BST(vector<int>&nums,int i,int n)
    {
        if(i>n)
        {
            return NULL;
        }
        int mid=i+(n-i)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=BST(nums,i,mid-1);
        root->right=BST(nums,mid+1,n);
        
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return BST(nums,0,n-1);
        
    }
};
