class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<vector<bool>> visited;
		for(int i=0;i<matrix.size();++i)
		{
			vector<bool> inVis;
			for(int j=0;j<matrix[i].size();++j)
			{
				inVis.push_back(false);
			}
			visited.push_back(inVis);
		}
		vector<int> result;
		resultHandle(0,0,matrix,visited,result,0);
		return result;
	}

	void resultHandle(int x,int y,vector<vector<int>>& matrix,vector<vector<bool>>& visited,vector<int>& result,int dir)
	{
		if (x>=0&&x<matrix.size()&&y>=0&&y<matrix[x].size()&&visited[x][y]==false)
		{
			visited[x][y]=true;
			result.push_back(matrix[x][y]);
			switch (dir)
			{
			case 0:
				resultHandle(x,y+1,matrix,visited,result,0);
				break;
			case 1:
				resultHandle(x+1,y,matrix,visited,result,1);
				break;
			case 2:
				resultHandle(x,y-1,matrix,visited,result,2);
				break;
			case 3:
				resultHandle(x-1,y,matrix,visited,result,3);
				break;
			default:
				break;
			}
			resultHandle(x,y+1,matrix,visited,result,0);
			resultHandle(x+1,y,matrix,visited,result,1);
			resultHandle(x,y-1,matrix,visited,result,2);
			resultHandle(x-1,y,matrix,visited,result,3);
		}
	}
};