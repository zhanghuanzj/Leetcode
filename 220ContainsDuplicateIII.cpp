class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		set<int> window;
		for (int i=0;i<nums.size();++i) {
			if (i>k){
				window.erase(nums[i-k-1]);
			}
			auto it = window.lower_bound(nums[i]-t);
			if (it!=window.end() && abs(*it - nums[i])<=t){
				return true;
			}
			window.insert(nums[i]);
		}
		return false;
	}
};