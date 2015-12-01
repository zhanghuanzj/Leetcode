class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		map<int,int> vars;
		for(int i=0;i<nums.size();++i)
		{
			if (vars.count(nums[i]))
			{
				if (i-vars[nums[i]]<=k)
				{
					return true;
				}
			}
			vars[nums[i]]=i;
		}
		return false;
	}
};