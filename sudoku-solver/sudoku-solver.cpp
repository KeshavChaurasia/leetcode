class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char num){
        // check if the num is in same row
        for(int i = 0; i < 9; i++){
            if(board[row][i] == num) return false;
        }
        // check if the num is in the same column
        for(int i = 0; i < 9; i++){
            if(board[i][col] == num) return false;
        }
        // check if the num is in the same grid
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i + startRow][j + startCol] == num) return false;
            }
        }
        
        return true;
    }
    
    bool solveSudoku(vector<vector<char>>& board, int row, int col){
        int n = board.size();
        // check if we have reached 8th row and 9th column
        // to stop backtracking
        if(row == n-1 && col == n) return true;
        
        // check if column becomes 9th column
        if(col == n) {
            row++;
            col = 0;
        }
        
        // check if the grid already contains value
        if(board[row][col] != '.') 
            return solveSudoku(board, row, col+1);
        
        for(int num = 1; num <= n; num++){
            if(isSafe(board,row,col,num + '0')){
                board[row][col] = (char)(num + '0');
                if(solveSudoku(board,row,col+1))
                    return true;
            }
            board[row][col] = '.';
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board,0,0);
    }
};