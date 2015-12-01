class Solution {
public:
	int findMin(vector<int>& nums) {
		int size = nums.size();
		int left=0,right=size-1;
		int mid;
		while(left<right)
		{
			while(left<size-1&&nums[left]==nums[left+1])
				++left;
			while(right>0&&nums[right]==nums[right-1])
				--right;
			if (nums[right]==nums[left])
			{
				++left;
			}
			mid = (left+right)/2;
			if (nums[mid]>nums[right])
			{
				left = mid+1;
			}
			else
			{
				right = mid;
			}
		}
		return nums[right];
	}
};