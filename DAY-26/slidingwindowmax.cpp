class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> ans;
        int i = 0;
        int j = 0;
        int sum = 0;
        int mxsu = INT_MIN;
        int n=arr.size();
        int val=0;
        while (j < n)
        {
            sum = sum + arr[j];
            val=max(val,arr[j]);
            
            if (j - i + 1 < k)
            {
                j++;
            }
            else if (j - i + 1 == k)
            {
                mxsu = max(sum, mxsu);
                 ans.push_back(val);
                sum = sum - arr[i];
                i++;
                j++;
            }
           
        }
        return ans;
    }
};
