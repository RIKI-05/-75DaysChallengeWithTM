class Solution {
public:
int subarraysWithKDistinct(vector<int>& nums, int k) {
        int j=0, u=0, res=0, maxi=0, nsub=0;
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            // Part 1 : Count Unique nums
            m[nums[i]]++;
            if (m[nums[i]]==1)
                u++;
            
            // Part 2 : If Unique nums == k, find maxi upto where uniques are still k
            if(u==k) {
                maxi = i;
                while(maxi+1<nums.size() && m[nums[maxi+1]]>0)
                    maxi++;
                // num of valid subarrays :
                nsub = maxi - i + 1;
            }
            
            // Part 3 : reduce window from left, while maintaining uniques to k
            // for every iteration, add previoursly calculated num of valid subarrays.
            while (u==k && j<nums.size()) {
                res += nsub;
                m[nums[j]]--;
                if (m[nums[j]] == 0)
                    u--;
                j++;
            }
        }
        return res;
    }
};