class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int size = dungeon.front().size();
		vector<int> hp(size+1,INT_MAX);  //到达目的所需的最小生命值
		hp[size-1] = 1;
		for (int i=dungeon.size()-1;i>=0;--i) {
			for (int j=size-1;j>=0;--j) {
				hp[j] = max(1,min(hp[j],hp[j+1])-dungeon[i][j]);
			}
		}
		return hp[0];
	}
};