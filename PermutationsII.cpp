class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		vector<vector<int>> result;
		do 
		{
			vector<int> permutation;
			for (int i : nums)
			{
				permutation.push_back(i);
			}
			result.push_back(permutation);
		} while (next_permutation(nums.begin(),nums.end()));
		return result;
	}
};