class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		set<int> vars;
		for(int var : nums)
		{
			if (vars.count(var))
			{
				return true;
			}
			else{
				vars.insert(var);
			}
		}
		return false;
	}
};