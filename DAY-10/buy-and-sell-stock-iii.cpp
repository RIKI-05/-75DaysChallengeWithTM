int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>sell(n,0);
        /*
        this vector strore profit of 1 trans 0 to ith day
        */
        int min_price=prices[0];
        for(int i=1;i<n;i++){
            min_price=min(min_price,prices[i]);
            int cur=prices[i]-min_price;
            sell[i]=max(sell[i-1],cur); 
            /* its also posible that we sell befor today*/
        }
        vector<int>buy(n,0);
        /* its store maximum profit of 1 trans if we buy today*/
        int max_price=prices[n-1];
        for(int i=n-2;i>=0;i--){
            max_price=max(max_price,prices[i]);
            int cur=max_price-prices[i];
            buy[i]=max(buy[i+1],cur);
        }
        int max_profit=0;
        for(int i=0;i<n;i++){
           max_profit=max(max_profit,buy[i]+sell[i]);
        }
        return max_profit;
    }