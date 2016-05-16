class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> result(amount+1,INT_MAX);
		result[0] = 0;
		for (int i = 1; i <= amount; ++i)
		{
			for (int j = 0; j < coins.size(); ++j)
			{
				if (i-coins[j]>=0&&result[i-coins[j]]!=INT_MAX)
				{
					result[i] = min(result[i],result[i-coins[j]]+1);
				}
			}
		}
		return (result[amount]==INT_MAX&&amount!=0)?-1:result[amount];
	}
};