class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int first = INT_MAX;
		int second = INT_MAX;
		for (size_t i=0;i+1<nums.size();++i)
		{
			if (nums[i]<nums[i+1]&&first>nums[i]&&second>nums[i+1])
			{
				first = nums[i];
				second = nums[i+1];
			}
			if (nums[i]>second||nums[i+1]>second)
			{
				return true;
			}
			if (nums[i]>first&&nums[i]<second)
			{
				second = nums[i];
			}
		}
		return false;
	}
};