 int findPeakElement(vector<int>& nums) {
        
        int n=nums.size();
        
        // We have to find the just local maxima , as if nums[idx]>nums[idx-1] and
        // nums[idx] > nums[idx+1]  , then it is local maxima 
        
        if(n==1)
        {
            return 0;
        }
        
        if(nums[0]>nums[1])
        {
            return 0;
        }
        
        if(nums[n-1]>nums[n-2])
        {
            return n-1;
        }
        
        // Now apply simple binary search 
        
        int l=0 , r=n-1;
        
        while(l<=r)
        {
            int mid=(l+(r-l)/2);
            int val1 , val2;
            if(mid+1<n)
            {
                val1=nums[mid+1];
            }
            else
            {
                val1=INT_MIN;
            }
            
            if(mid-1>=0)
            {
                val2=nums[mid-1];
            }
            else
            {
                val2=INT_MIN;
            }
            
            if( nums[mid]>val2 && nums[mid]>val1)
            {
                return  mid;
            }
            else
            if(nums[mid]>val2 && nums[mid]<val1)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return -1;
    }