class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<vector<int>> Vec;
		for(int i=0;i<triangle.size();++i)
		{
			vector<int> Invec;
			for(int j=0;j<triangle[i].size();++j)
			{
				if (i==0&&j==0)
				{

					Invec.push_back(triangle[i][j]);
				}
				else if (j==0)
				{
					Invec.push_back(Vec[i-1][j]+triangle[i][j]);
				}
				else if(j==triangle[i].size()-1)
				{
					Invec.push_back(Vec[i-1][j-1]+triangle[i][j]);
				}
				else
				{
					Invec.push_back(min(Vec[i-1][j],Vec[i-1][j-1])+triangle[i][j]);
				}
			}
			Vec.push_back(Invec);
		}
		int mini = 0x7fffffff;
		int index = Vec.size()-1;
		for (int i=0;i<Vec[Vec.size()-1].size();++i)
		{
			if (mini>Vec[index][i])
			{
				mini = Vec[index][i];
			}
		}
		return mini;	
	}
};