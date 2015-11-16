class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		vector<int> vec;
		int m = grid.size();
		if (m==0)
		{
			return 0;
		}
		int n = grid[0].size();
		if (n==0)
		{
			return 0;
		}
		for(int i=0;i<n;++i)
		{
			if (i==0)
			{
				vec.push_back(grid[0][i]);
			}
			else
			{
				vec.push_back(grid[0][i]+vec[i-1]);
			}
		}
		for(int i=1;i<m;++i)
		{
			for(int j=0;j<n;++j)
			{
				if (j==0)
				{
					vec[j]+=grid[i][j];
				}
				else
				{
					vec[j]=min(vec[j],vec[j-1])+grid[i][j];
				}
			}
		}
		return vec.back();
	}
};