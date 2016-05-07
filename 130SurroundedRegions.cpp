class Solution {
public:
	void solve(vector<vector<char>>& board) {
		int m = board.size();
		if (m==0) return;
		int n = board.begin()->size();
		for (int i=0;i<n;++i)
		{
			update(board,0,i);
			update(board,m-1,i);
		}
		for (int i=0;i<m;++i)
		{
			update(board,i,0);
			update(board,i,n-1);
		}
		for (int i=0;i<m;++i)
		{
			for (int j=0;j<n;++j)
			{
				if (board[i][j]=='1')
				{
					board[i][j] = 'O';
				}
				else if (board[i][j]=='O')
				{
					board[i][j] = 'X';
				}
			}
		}
	}

	void update(vector<vector<char>>& board,int i,int j)
	{
		if (board[i][j]!='O')
		{
			return;
		}
		int x[] = {-1,1,0,0};
		int y[] = {0,0,-1,1};
		queue<pair<int,int>> q;
		board[i][j] = '1';
		q.push(make_pair(i,j));
		while (!q.empty())
		{
			pair<int,int> p = q.front();
			q.pop();
			for (int k=0;k<4;++k)
			{
				int nx = p.first+x[k];
				int ny = p.second+y[k];
				if (nx>=0&&nx<board.size()&&ny>=0&&ny<board.begin()->size()&&board[nx][ny]=='O')
				{
					q.push(make_pair(nx,ny));
					board[nx][ny] = '1';
				}
			}
		}
	}
};