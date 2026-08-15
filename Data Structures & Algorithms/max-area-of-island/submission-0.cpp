class Solution{
private:
    int res;
    int backtracking(vector<vector<int>> &grid,vector<vector<bool>> &visited, int row,int col){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || visited[row][col] || grid[row][col]==0) return 0;
        visited[row][col]=true;
        int area=1+ backtracking(grid,visited,row-1,col)+ backtracking(grid,visited,row+1,col)+ backtracking(grid,visited,row,col-1)+ backtracking(grid,visited,row,col+1);
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        res=0;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j] && grid[i][j]==1){
                    res=max(res,backtracking(grid,visited,i,j));
                }
            }
        }
        return res;
    }
};
