class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rows,col;
        rows=matrix.size();
        col=matrix[0].size();
        int left=0,top=0,bottom,right,dir=0;
        bottom=rows-1;
        right=col-1;
        while(left<=right && top<=bottom){
            if(dir==0){
                for(int i=left; i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
                dir=1;
            }
            else if(dir==1){
                for(int i=top; i<=bottom;i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
                dir=2;
        }
           else if(dir==2){
                for(int i=right; i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
                dir=3;}
            else if(dir==3){
                for(int i=bottom; i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
                dir=0;
        
    }
            else break;}
        return ans;
    }
};