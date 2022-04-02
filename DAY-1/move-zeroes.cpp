class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count =0;
        vector<int>a;
        int i =0;
        for(auto x: nums){
            if(x==0)count++;
            else{
                nums[i]=x;
                i++;
            }
        }
        while(i<nums.size()){
            nums[i++]=0;
        }
        
        
    }
};