class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
    map<int,int>m;
        set<int>s;
        int d=0;
        for(auto x : nums){
           s.insert(x);
            m[x]++; 
        }
        if(k==0){
            for(auto x :m){
                if(x.second>=2)d++;
            }
            return d;
        }
        int c=0;
        for(auto x :s){
            if(s.find(k+x)!=s.end()){
                c++;
            }
        }
        
        return c;
    }
};