class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        map<int,pair<int,int>>m;
        int f=-1,l=-1;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==target and f==-1){
                f=i;
                l=i;
            }
            else if(nums[i]==target){
                l=i;
            }
        }
        vector<int>ans;
        ans.push_back(f);
        ans.push_back(l);
        return ans;
    }
};