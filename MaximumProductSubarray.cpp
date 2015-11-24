class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int result = INT_MIN;
		int rmin_pre = nums[0],rmin_next;
		int rmax_pre = nums[0],rmax_next;
		result = max(result,rmax_pre);
		for(int i=1;i<nums.size();++i)
		{
			rmax_next = max(max(rmax_pre*nums[i],rmin_pre*nums[i]),nums[i]);
			rmin_next = min(min(rmax_pre*nums[i],rmin_pre*nums[i]),nums[i]);
			result = max(result,rmax_next);
			rmin_pre = rmin_next;
			rmax_pre = rmax_next;
		}
		return result;
	}
};