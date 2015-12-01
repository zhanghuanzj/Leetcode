class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int size = nums.size();
		for(int i=0;i<size;++i)
		{
			if (i==0&&size==1)
			{
				return i;
			}
			else if (i==0&&nums[i]>nums[i+1])
			{
				return i;
			}
			else if (i==size-1&&nums[i]>nums[i-1])		
			{
				return i;
			}
			else if (i>0&&i<size-1&&nums[i]>nums[i-1]&&nums[i]>nums[i+1])
			{
				return i;
			}
		}
	}
};