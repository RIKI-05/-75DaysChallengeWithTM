class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
     int ans =0;
        int n = grid.size();
        int m = grid[0].size();
        int i =0;
        int j = m-1;
        while(i>=0 and i<n and j>=0 and j<m){
            if(grid[i][j]<0){
                ans+=(n-i);
                j--;
            }
            else{
                i++;
            }
        }
        
        return ans;
    }
};