class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int left = -1;
		int right = nums.size()-1;
		for(int i=right;i>0;--i)
		{
			if(nums[i-1]<nums[i])
			{
				left = i-1;
				break;
			}
		}
		for(int i=right;i>=0;--i)
		{
			if (left==-1)
			{
				break;
			}
			if (nums[i]>nums[left])
			{
				right = i;
				int temp = nums[left];
				nums[left] = nums[right];
				nums[right] = temp;
				break;
			}
		}	
		swap(nums,left+1,nums.size()-1);
	}

	void swap(vector<int>& nums,int left,int right)
	{
		while(left<right)
		{
			int temp = nums[left];
			nums[left++] = nums[right];
			nums[right--] = temp;
		}
	}
};