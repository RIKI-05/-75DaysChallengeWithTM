  bool check(vector<int>&nums,int m,int operations)
    {
        int op=0;
        for(int i=0;i<nums.size();i++)
        {
            op+=(nums[i]/m);
            if(nums[i]%m==0)op--;
        }
        return op<=operations?1:0;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int si=1;
        int end=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(si<=end)
        {
            int mid=si+(end-si)/2;
           
            if(check(nums,mid,maxOperations))
            {
               
                ans=mid;
                end=mid-1;
                
            }
            else
            {
                si=mid+1;
            }
        }
      return ans;
        
    }