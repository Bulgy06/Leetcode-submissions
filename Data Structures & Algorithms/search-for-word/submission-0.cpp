class Solution {
private:
    int rows;
    int cols;
    bool dfs(vector<vector<char>> &board,vector<vector<bool>> &visited,string word,int row,int col, int i){
        if(i==word.length()){
            return true;
        }
        if(row<0 || row>=rows || col<0 || col>=cols || board[row][col]!=word[i] || visited[row][col]){
            return false;
        }

        visited[row][col]=true;
        bool res=dfs(board,visited,word,row-1,col,i+1) ||
        dfs(board,visited,word,row,col+1,i+1) ||
        dfs(board,visited,word,row+1,col,i+1) ||
        dfs(board,visited,word,row,col-1,i+1);
        visited[row][col]=false;
        return res;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        rows=board.size();
        cols=board[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board,visited,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
