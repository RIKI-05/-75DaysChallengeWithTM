

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tot =0;
        int sum=0;
        for(auto x: nums){
            tot+=x;
        }
        
        for(int i =0;i<nums.size();i++){
            
            if(sum==(tot-sum-nums[i])){
                return i;
            }
            sum+=nums[i];
        }
        
        return -1;
    }
};