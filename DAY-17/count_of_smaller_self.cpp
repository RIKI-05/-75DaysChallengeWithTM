class Solution{
public:
void merge(vector<pair<int,int>>&v,vector<int>&count,int low,int mid,int high)
    {
        int i=low;
        int j=mid+1;
        vector<pair<int,int>>temp(high-low+1);
        int k=0;
        while(i<=mid & j<=high)
        {
            if(v[i].first<=v[j].first)
            {
                temp[k++]=v[j++];
            }
            else
            {
                count[v[i].second]+=(high-j+1);
                temp[k++]=v[i++];
            }
        }
        while(i<=mid)
        {
            temp[k++]=v[i++];
        }
        while(j<=high)
        {
            temp[k++]=v[j++];
        }
        for(int i=low;i<=high;i++)
        {
            v[i]=temp[i-low];
        }
    }
    void mergeSort(vector<pair<int,int>>&v,vector<int>&count,int low,int high)
    {
        if(low<high){
            int mid=low+(high-low)/2;
            mergeSort(v,count,low,mid);
            mergeSort(v,count,mid+1,high);
            merge(v,count,low,mid,high);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<nums.size();i++)
        {
            pair<int,int>p;
            p.first=nums[i];
            p.second=i;
            v[i]=p;
        }
        vector<int>count(n,0);
        mergeSort(v,count,0,n-1);
        return count;
        
    }
};
