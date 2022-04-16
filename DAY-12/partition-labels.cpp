class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        
        for(int i=0; i<s.size(); i++){
            mp[s[i]] = i;
        }
        
        int size = 1;
        int end = 0;
        vector<int>ans;
        for(int i=0; i<s.size(); i++){
            if(mp[s[i]] > end){
                end = mp[s[i]];
            }
            if(i == end){
                ans.push_back(size);
                size = 0;
            }
            size++;
        }
        
        return ans;
    }
};