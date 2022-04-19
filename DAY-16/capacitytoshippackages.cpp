 bool cursplit(vector<int>&weights,int maxw,int days)
    {
        int totaldays=0;
        int curw=0;
        for(int i=0;i<weights.size();i++)
        {
            if(curw+weights[i]<=maxw)
            {
                curw+=weights[i];
            }
            else
            {
                curw=weights[i];
                totaldays++;
            }
        }
        return 1+totaldays<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        //same as split array with largest sum can split into m subarrays
        int n=weights.size();
        //so the weight of the days 
        int low=0;
        int high=0;
        for(int i=0;i<n;i++)
        {
            low=max(low,weights[i]);
            high+=weights[i];
            
        }
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(cursplit(weights,mid,days))
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }