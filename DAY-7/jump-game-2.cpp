class Solution {
public:
    int jump(vector<int>& nums) {
        int curr = 0;
        int jump = 0;
        int ans =0;
        for(int i =0;i<nums.size()-1;i++){
            jump = max(i+nums[i],jump);
            if(curr == i){
                ans++;
                curr = jump;
            }
        }
        
        return ans;
    }
};