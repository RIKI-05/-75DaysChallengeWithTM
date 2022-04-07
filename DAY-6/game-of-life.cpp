using board_t = vector<vector<int>>;

class Solution {
public:

    const vector<int> x {1, 1, 1, 0, 0, -1, -1, -1};
    const vector<int> y {0, 1, -1, 1, -1, -1, 1, 0};
    
    const int MAX_NEIGHBOURS = 8;
    
    const int IS_LIVE = 1 << 1;
    
    bool isValid(const int row, const int col, const int ROW_MAX, const int COL_MAX) {
        return (row >= 0 && row < ROW_MAX && col >=0 && col < COL_MAX);
    }
    
    int getNumLiveNeighbours(const board_t& board, const int curr_x, const int curr_y,
                         const int ROW_MAX, const int COL_MAX) {
        int count = 0;
        int new_x = 0;
        int new_y = 0;
        for(int i = 0; i < MAX_NEIGHBOURS; i++) {
            new_x = curr_x + x[i];
            new_y = curr_y + y[i];
            if(isValid(new_x, new_y, ROW_MAX, COL_MAX) && (board[new_x][new_y] & IS_LIVE)) count++; 
        }
        return count;
    }
    
    int getNewCellValue(const bool currLive, const int numLiveNeighbours) {
        if (!currLive && numLiveNeighbours == 3) return 1;
        if (currLive && numLiveNeighbours < 2) return 0;
        if (currLive && (numLiveNeighbours == 2 || numLiveNeighbours == 3)) return 1;
        if (currLive && numLiveNeighbours > 3) return 0;
        return currLive ? 1 : 0;
    } 
    
    void gameOfLife(board_t& board) {
        
        const int ROW_MAX = board.size();
        const int COL_MAX = board[0].size();
        
        for (auto &row: board)
            for (auto &elem : row)
                elem = elem << 1;
        
        for (int i = 0; i < ROW_MAX; i++)
            for(int j = 0; j < COL_MAX; j++) {
                const int numLiveNeighbours = getNumLiveNeighbours(board, i, j, ROW_MAX, COL_MAX);
                const bool isCurrLive = board[i][j] & IS_LIVE;
                board[i][j] = board[i][j] | getNewCellValue(isCurrLive, numLiveNeighbours);
            }
        
        for (auto &row: board)
            for (auto &elem : row) {
                elem = elem & ~(1 << 1);
            }
    }
};