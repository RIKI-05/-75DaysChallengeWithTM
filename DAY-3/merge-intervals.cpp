class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n-1;i++){
            temp.clear();
            if(intervals[i][1]>=intervals[i+1][0] and intervals[i][1]>=intervals[i+1][1]){
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i][1]);
                intervals[i] = {-1,-1};
                intervals[i+1] = temp;
            }
            else if(intervals[i][1]>=intervals[i+1][0]){
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i+1][1]);
                intervals[i] = {-1,-1};
                intervals[i+1] = temp;
            }
            
            
        }
        for(auto x : intervals){
            if(x[0]!=-1){
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};