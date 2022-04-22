class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        unordered_map<int,int>m;
        for(auto x : nums){
            m[x]++;
        }
        
        for(auto x : m){
            minh.push({x.second,x.first});
            if(minh.size()>k)minh.pop();
        }
        
        vector<int>res;
        while(minh.size()>0){
            res.push_back(minh.top().second);
            minh.pop();
        }
        
        return res;
    }
};