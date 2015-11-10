class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		const int rNum = matrix.size();
		if (rNum==0)
		{
			return;
		}
		const int cNum = matrix[0].size();
		vector<bool> rowSet(rNum,0);
		vector<bool> columnSet(cNum,0);
		for(int i=0;i<rNum;++i)
		{
			for(int j=0;j<cNum;++j)
			{
				if (matrix[i][j]==0)
				{
					rowSet[i]=true;
					columnSet[j]=true;
				}
			}
		}
		for(int i=0;i<rNum;++i)
		{
			for(int j=0;j<cNum;++j)
			{
				if (rowSet[i]||columnSet[j])
				{
					matrix[i][j]=0;
				}
			}
		}
	}
};