class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a[3]={0};
        for(int i:nums)
            a[i]++;
        int k=0;
        int q=0;
        for(auto i:a){
            for(int j=0;j<i;j++){
                nums[q++]=k;
            }
            ++k;
        }
    }
};