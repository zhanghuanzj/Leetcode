class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.size()==0||matrix[0].size()==0)
		{
			return;
		}
		bool flag = false;
		int x,y,temp;
		int iHalf = matrix.size()/2;
		int jHalf = iHalf;
		if (matrix.size()%2==1)
		{
			jHalf++;
		}
		for (int i=0;i<iHalf;++i)
		{
			for (int j=0;j<jHalf;++j)
			{
				x=i;
				y=j;
				int value = matrix[x][y];
				for(int k=0;k<4;++k)
				{
					int tx,ty;
					tx = y;
					ty = matrix.size()-1-x;
					temp = matrix[tx][ty];
					matrix[tx][ty] = value;
					value = temp;
					x = tx;
					y = ty;
				}
			}
		}
	}
};