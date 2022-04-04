class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>dp(n,0);
        for(int i =0;i<n-1;i++){
            if(prices[i]<prices[i+1]){
                dp[i+1]=prices[i+1]-prices[i];
            }
        }
        
        int ans =0;
        for(auto x : dp){
            ans+=x;
        }
    return ans;
    }
};