class Solution {
public:
    bool dfs(vector<vector<char>>&board,int i ,int j, string word,int k){
        int n = board.size();
        int m = board[0].size();
        if(k==word.length())return true;
        if(i<0 || j<0 ||i>=n ||j>=m ||board[i][j]!=word[k])
            return false;
        
        char temp = board[i][j];
        board[i][j]=' ';
        bool found = dfs(board,i+1,j,word,k+1) || dfs(board,i-1,j,word,k+1)||       dfs(board,i,j-1,word,k+1)|| dfs(board,i,j+1,word,k+1);
        
        board[i][j]=temp;
        
        return found;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int k=0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[k] and dfs(board,i,j,word,k)) return true;
            }
        }
        
        return false;
    }
};
