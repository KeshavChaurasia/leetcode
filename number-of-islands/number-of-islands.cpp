class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col){
        // check if not out of boundary
        if(row < 0 || row >= (int) grid.size() || col < 0 || col >= (int)grid[0].size() || grid[row][col] == '0') return;
        
        // once visited this land then turn this to water so that we don't have to search this place
        grid[row][col] = '0';
        
        // mark the lands visited
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // base case
        if(grid.size() == 0) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int totalIslands = 0;
        
        // we go through all the nodes
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == '1'){
                    totalIslands++;
                    dfs(grid, row,col);
                } 
            }
        }
        return totalIslands;
    }
};