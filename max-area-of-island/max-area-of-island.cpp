class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int & currArea){
        // check for out of boundary
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0 ) return;
        
        // increase the area
        currArea = currArea + 1;
        
        // mark this land
        grid[row][col] = 0;
        
        // traverse to next land
        dfs(grid, row + 1, col, currArea);
        dfs(grid, row - 1, col, currArea);
        dfs(grid, row, col + 1, currArea);
        dfs(grid, row, col - 1, currArea);

    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // base case
        if(grid.size() == 0) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;
        int currArea = 0;
        
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == 1){
                    currArea = 0;
                    dfs(grid, row, col, currArea);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }
};