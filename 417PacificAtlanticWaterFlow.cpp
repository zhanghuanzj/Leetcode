class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> result;
        int m = matrix.size();
        if(m==0) return result;
        int n = matrix.front().size();
        vector<vector<int>> record(m,vector<int>(n,0));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if((i==0||j==0)&&record[i][j]!=1) dfs(matrix,record,i,j,1);
                if((i==m-1||j==n-1)&&record[i][j]!=2) dfs(matrix,record,i,j,2);
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(record[i][j]==15) result.push_back(make_pair(i,j));
            }
        }
        return result;
    }
    void dfs(vector<vector<int>>& matrix,vector<vector<int>>& record,int x,int y,int flag){
        int m = matrix.size(),n = matrix.front().size();
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        record[x][y] |= flag;
        record[x][y] |= flag<<2;
        for(int i=0;i<4;++i){
            int px = x+dx[i];
            int py = y+dy[i];
            if(px>=0&&px<m&&py>=0&&py<n&&!(record[px][py]&(flag<<2))&&matrix[x][y]<=matrix[px][py]){
                dfs(matrix,record,px,py,flag);
            }
        }
    }
};