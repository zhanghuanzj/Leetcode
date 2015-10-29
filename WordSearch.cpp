#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	

	bool exist(vector<vector<char>>& board, string word) {
		vector<vector<bool>> visited;
		for (int i = 0; i < board.size(); ++i)
		{
			vector<bool> visitTemp;
			for (int j = 0; j < board[0].size(); ++j)
			{
				visitTemp.push_back(false);
			}
			visited.push_back(visitTemp);
		}
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				if (isFind(board,word,visited,make_pair(i,j),0))
				{
					return true;
				}
			}

		}
		return false;
	}

	bool isFind(vector<vector<char>>& board,string word,vector<vector<bool>>& visited,pair<int,int> index_pair,int number)
	{
		int direction[2][4] = {
			{0,0,-1,1},
			{-1,1,0,0}
		};

		int x = index_pair.first;
		int y = index_pair.second;
		if (x<0||x>=board.size()||y<0||y>=board[0].size())
		{
			return false;
		}
		if (number==word.size()-1)
		{
			if (!visited[x][y]&&board[x][y]==word[number])
			{
				return true;
			}
			return false;
		}
		else
		{
			if (!visited[x][y]&&board[x][y]==word[number])
			{
				visited[x][y]=true;
				for (int i = 0; i < 4; ++i)
				{
					if (isFind(board,word,visited,make_pair(x+direction[0][i],y+direction[1][i]),number+1))
					{
						return true;
					}
				}
				visited[x][y]=false;
			}
		}
		return false;
	}
};

int main()
{
	Solution solution;
	vector<vector<char>> vecs;

	for (int i=0;i<3;i++)
	{
		vector<char> vec;
		for (int j=0;j<4;j++)
		{
			char c;
			cin>>c;
			vec.push_back(c);
		}
		vecs.push_back(vec);
	}

	while (true)
	{
		string str;
		cin>>str;
		cout<<solution.exist(vecs,str);
	}
	
}