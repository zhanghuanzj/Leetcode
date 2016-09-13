class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]=='1'){
                    ++count;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid,int x,int y){
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        grid[x][y] = '0';
        for(int i=0;i<4;++i){
            int nx = x+dx[i],ny = y+dy[i];
            if(nx>=0&&nx<grid.size()&&ny>=0&&ny<grid[0].size()&&grid[nx][ny]=='1'){
                dfs(grid,nx,ny);
            }
        }
    }
};