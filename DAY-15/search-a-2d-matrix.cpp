class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // BRUTE FORCE 
        // for(auto x:matrix){
        //     for(auto y:x){
        //         if(target==y)return true;
        //     }
        // }
        // return false;
        
int m=matrix.size();
    int n=matrix[0].size();
        
        if(target<matrix[0][0] || target>matrix[m-1][n-1]) return false;
    
    int r=0,c=n-1;
    
    while( r<m && c>=0){
        
        if(matrix[r][c]==target){
            return true;
        }
        
        else if(matrix[r][c]>target){
            c--;
        }
        
        else{
            r++;
        }
        
    }
    
    return false;
    }
};