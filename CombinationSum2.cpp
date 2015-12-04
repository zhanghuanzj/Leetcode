class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(),candidates.end());
		vector<int> temp;
		set<vector<int>> result;
		solve(candidates,target,result,temp,0);
		vector<vector<int>> vec(result.begin(),result.end());
		return vec;
	}
	void solve(vector<int>& candidates,int target, set<vector<int>>& result,vector<int>temp,int index)
	{
		if (target==0) {
			result.insert(temp);
		}
		else
		{
			for(int i=index;i<candidates.size();++i)
			{
				if (candidates[i]<=target) {
					temp.push_back(candidates[i]);
					solve(candidates,target-candidates[i],result,temp,i+1);
					temp.pop_back();
				}
			}
		}
	}
};