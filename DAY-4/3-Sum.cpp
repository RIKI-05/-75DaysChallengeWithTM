class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>v;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size();i++){
            if(i>0 && nums[i] == nums[i-1])continue;
    
            int l = i + 1; int h = n - 1;
            while( l < h ){
                int cur = nums[ i ]+ nums[ l ]+nums[ h ];
                if(cur == 0){
        
                        v.push_back({nums[ i ] , nums[ l ] , nums[ h ]});
                        int le = nums[ l ] , he = nums[ h ];  //if we don't write 16-22 line code will give duplicate outputs
        
                        while(l < h && nums[ l ] == le)  // Skipping dupplicates
                                l++;     
                                    }
                        if(cur < 0)
                            l++;
        
                        else
                            h--;
                            }
    
                            }
        return v;
    }
};