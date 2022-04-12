public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int>m;
        for(auto x : nums){
            m[x]++;
        }
        
        int k =1;
        for(auto x : m){
            if(m.find(k)==m.end()){
                return k;
            }
            else k=k+1;
        }
        return k;
    }
};