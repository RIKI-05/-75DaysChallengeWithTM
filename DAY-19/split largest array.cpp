  bool cursplit(vector<int>&nums,int maxsum,int m)
    {
        int cursum=0;
        int totalparts=0;
        for(int i=0;i<nums.size();i++)
        {
            if(cursum+nums[i]<=maxsum)
            {
                cursum+=nums[i];
            }
            else
            {
                cursum=nums[i];
                totalparts++;
            }
        }
        return totalparts+1<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        //the least max sum can be of the maximum element from the nums
        int low=0;
        int high=0;//high is the range in which we can get the largest sum among the m subarrays;
        for(int i=0;i<n;i++)
        {
            low=max(low,nums[i]);
            high+=nums[i];
        }
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(cursplit(nums,mid,m))
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
