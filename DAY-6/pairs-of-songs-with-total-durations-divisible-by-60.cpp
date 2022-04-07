class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        map<int,int>m;
        for(auto x : time){
            if(x%60 == 0){
                count+=m[0];
            }
            else{
                count+=m[60-x%60];
            }
            m[x%60]++;
        }
        
        return count;
    }
};