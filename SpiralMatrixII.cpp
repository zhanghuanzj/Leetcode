class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		int nx[]={0,1,0,-1};
		int ny[]={1,0,-1,0};
		vector<vector<int>> result;
		for(int i=0;i<n;++i)
		{
			vector<int> inVec(n);
			result.push_back(inVec);
		}
		int num = pow(n,2);
		int dir = 0;
		int m = n;
		int value=1,k,x=0,y=-1;
		while(value<=num)
		{
			if (dir%2==0)
			{
				k=n;
				m--;
			}
			else
			{
				k=m;
				n--;
			}
			while(k--)
			{
				x+=nx[dir];
				y+=ny[dir];		
				result[x][y]=value++;
			}
			dir = (dir+1)%4;
		}
		return result;
	}
};