class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans=0;
        vector<int>dp(n);
        int minv = prices[0];
        dp[0]=0;
        for(int i = 1;i<n;i++){
            if(prices[i]>minv){
                dp[i]=prices[i]-minv;
            }
            else{
                minv = prices[i];
                dp[i]=0;
            }
        }
        for(auto x : dp){
            ans = max(ans,x);
        }
        
        return ans;
    }
};