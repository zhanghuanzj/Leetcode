class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
		set<vector<int>> Vec;
		int size = nums.size();
		int subsetsNum = pow(2,size);
		for (int i=0; i<subsetsNum; ++i) {
			vector<int> vec;
			for (int j=0; j<size; ++j) {
				if (i>>j&1) {
					vec.push_back(nums[j]);
				}
			}
			Vec.insert(vec);
		}
		vector<vector<int>> returnVec;
		for (auto ele: Vec)
		{
			returnVec.push_back(ele);
		}
		return returnVec;
    }
};