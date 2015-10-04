#include <iostream>
#include <vector>
using namespace std;
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int n = board.size();
		int m = board[0].size();
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				int count = 0;
				for (int x=max(i-1,0);x<min(i+2,n);x++)
				{
					for (int y=max(j-1,0);y<min(j+2,m);y++)
					{
						count +=board[x][y]&1;
					}
				}
				/*由于把本身的方格也考虑了进来，所以count==3,分为两种情况
				*		外围2+自身1
				*		外围3+自身0
				*		这两种情况使得细胞都可以活
				*还有一种情况就是外围3+自身1 = 4
				*/
				if (count==3||(board[i][j]&&count==4))   
				{
					board[i][j] |=2;
				}
			}
		}
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				board[i][j]>>=1;
			}
		}
	}
};

int main()
{
	vector<vector<int>> board;
	vector<int> x,y,z;
	x.push_back(1);
	x.push_back(0);
	x.push_back(1);
	board.push_back(x);
	y.push_back(0);
	y.push_back(1);
	y.push_back(1);
	board.push_back(y);
	z.push_back(0);
	z.push_back(1);
	z.push_back(1);
	board.push_back(z);
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	Solution solution;
	solution.gameOfLife(board);

	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}