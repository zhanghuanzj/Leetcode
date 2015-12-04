class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> result;
		vector<int> temp;
		solve(k,n,1,result,temp);
		return result;
	}
	void solve(int k,int n,int index,vector<vector<int>> &result,vector<int>temp)
	{
		if (k==0&&n==0) {
			result.push_back(temp);
		}
		else
		{
			for(int i=index;i<=9;++i)
			{
				if (i<=n) {
					temp.push_back(i);
					solve(k-1,n-i,i+1,result,temp);
					temp.pop_back();
				}
			}
		}
	}
};