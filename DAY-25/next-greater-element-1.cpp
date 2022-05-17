
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums) {
        
        unordered_map<int,int> mp;
        stack<int> s;
        for(int i = nums.size()-1;i>=0;i--){
            
            while(!s.empty() and s.top()<=nums[i])s.pop();
            
            if(s.empty())mp[nums[i]]=-1;
            else mp[nums[i]]=s.top();
            
            s.push(nums[i]);
            
        }
        
        vector<int>ans;
        for(auto x : nums1){
            ans.push_back(mp[x]);
        }
        
        return ans;
    }
};

