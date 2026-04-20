class NumMatrix {
private:
    vector<vector<int>> sumMatrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        sumMatrix = vector<vector<int>>(rows+1, vector<int>(cols+1, 0));
        for(int i=1;i<rows+1;i++){
            for(int j=1;j<cols+1;j++){
                sumMatrix[i][j]=matrix[i-1][j-1]+sumMatrix[i-1][j]+sumMatrix[i][j-1]-sumMatrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumMatrix[row2+1][col2+1]-sumMatrix[row2+1][col1]-sumMatrix[row1][col2+1]+sumMatrix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */