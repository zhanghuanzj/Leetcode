class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
	    if (matrix.empty())
		{
			return 0;
		}
		int m = matrix.size();
		int n = matrix[0].size();
		vector<int> LSIndex;
		vector<int> RSIndex;
		vector<int> height;	
		for (int j=0;j<n;++j)
		{
			LSIndex.push_back(0);
			RSIndex.push_back(n);
			height.push_back(0);
		}
		int result = 0;
		for(int i=0;i<m;++i)
		{
			int left=0,right=n;
			for(int j=0;j<n;++j)
			{
				if (matrix[i][j]=='1')
				{
					++height[j];
					LSIndex[j]=max(LSIndex[j],left);
				}
				else
				{
					height[j]=0;
					LSIndex[j]=0;
					left = j+1;
				}
			}
			for(int j=n-1;j>=0;--j)
			{
				if (matrix[i][j]=='1')
				{
					RSIndex[j]=min(RSIndex[j],right);
				}
				else
				{
					RSIndex[j]=n;
					right = j;
				}
			}
			for(int j=0;j<n;++j)
			{
				result = max(result,(RSIndex[j]-LSIndex[j])*height[j]);
			}
		}
		return result;
	}
};