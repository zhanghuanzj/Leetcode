class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(),candidates.end());
		vector<int> temp;
		vector<vector<int>> result;
		solve(candidates,target,result,temp,0);
		return result;
	}
	void solve(vector<int>& candidates,int target, vector<vector<int>>& result,vector<int>temp,int index)
	{
		if (target==0) {
			result.push_back(temp);
		}
		else
		{
			for(int i=index;i<candidates.size();++i)
			{
				if (candidates[i]<=target) {
					temp.push_back(candidates[i]);
					solve(candidates,target-candidates[i],result,temp,i);
					temp.pop_back();
				}
			}
		}
	}
};