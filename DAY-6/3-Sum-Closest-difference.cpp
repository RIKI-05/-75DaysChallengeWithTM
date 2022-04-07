class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int diff = INT_MAX;
        int target_diff = INT_MAX;
        for(int i=0;i<n-2;i++){
            int l = i+1;
            int r = n-1;
            while(l<r){
                int curr = nums[i]+nums[l]+nums[r];
                
                if(target<curr){
                    r--;
                }
                else if(target>curr){
                    l++;
                }
                else{
                    return target;
                }
                if(abs(target-curr)<target_diff){
                    target_diff = abs(target-curr);
                    diff = curr;
                }
            }
        }
        
        return diff;
    }
};