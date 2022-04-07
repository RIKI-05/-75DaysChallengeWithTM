class Solution {
public:
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>>x;
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
        long long temp = target-nums[i]-nums[j]; 
        int l = j+1;
        int r = n-1;
        while(l<r){
            long long sum = nums[l]+nums[r];
            if(sum==temp){
                x.insert({nums[i],nums[j],nums[l],nums[r]});
                l++;
                r--;
            }else if(sum>temp){
                r--;
            }else{
                l++;
            }
        }
    }
    }
        
    
    
    for(auto t : x ){
        ans.push_back(t);
    }
    
    return ans;
}
};

