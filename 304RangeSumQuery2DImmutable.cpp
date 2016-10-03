class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix):Matrix(matrix) {
        int m = matrix.size();
        for(int i=0;i<m;++i){
            for(int j=0;j<matrix[0].size();++j){
                Matrix[i][j] += getSum(i-1,j)+getSum(i,j-1)-getSum(i-1,j-1);
            }
        }
    }
    int getSum(int x,int y){
        if(x<0||y<0) return 0;
        return Matrix[x][y];
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2,col2)-getSum(row1-1,col2)-getSum(row2,col1-1)+getSum(row1-1,col1-1);
    }
    vector<vector<int>> Matrix;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);