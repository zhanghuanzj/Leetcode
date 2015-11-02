class Solution {

public:
	int vec[100][100];
	int uniquePaths(int m, int n) {
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i==0||j==0)
				{
					vec[i][j]=1;
				}
				else
				{
					vec[i][j] = vec[i][j-1]+vec[i-1][j];
				}
			}
		}
		return vec[m-1][n-1];
	}
};