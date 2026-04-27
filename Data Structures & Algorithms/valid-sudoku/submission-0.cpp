class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int box=(i/3)*3 + j/3;
                if(isdigit(board[i][j])){
                    if(rows[i].contains(board[i][j]) || cols[j].contains(board[i][j]) || boxes[box].contains(board[i][j])){
                    return false;
                    }
                    else{
                        rows[i].insert(board[i][j]);
                        cols[j].insert(board[i][j]);
                        boxes[box].insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};
