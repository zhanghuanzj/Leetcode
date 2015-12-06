class Solution {
public:
	int firstMissingPositive(vector<int>& nums) 
	{
		int size = nums.size();
		for(int i=0;i<size;++i)
		{
			if (nums[i]>0&&nums[i]<=size&&nums[nums[i]-1]!=nums[i]) 
			{
				swap(nums[i],nums[nums[i]-1]);
				--i;
			}
		}
		int i=0;
		for(;i<size;++i)
		{
			if (nums[i]!=i+1) {
				break;
			}
		}
		return i+1;
	}
};