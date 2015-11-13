class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size()-1;
		if (right == -1)
		{
			return 0;
		}
		while(left<right)
		{
			int mid = (left+right)/2;
			if (nums[mid]>=target)
			{
				right = mid;
			}
			else
			{
				left = mid+1;
			}
		}
		if (nums[left]>=target)
		{
			return left;
		}
		else
		{
			return left+1;
		}
	}
};