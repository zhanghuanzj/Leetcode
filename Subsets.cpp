class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		vector<vector<int>> Vec;
		int size = nums.size();
		int subsetsNum = pow(2,size);
		for (int i=0; i<subsetsNum; ++i) {
			vector<int> vec;
			for (int j=0; j<size; ++j) {
				if (i>>j&1) {
					vec.push_back(nums[j]);
				}
			}
			Vec.push_back(vec);
		}
		return Vec;
	}
};