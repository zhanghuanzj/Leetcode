int lowerBound(vector<int>& nums,int target)
{
	int left = 0;
	int right = nums.size()-1;
	int mid = 0;
	if (right==-1)
	{
		return -1;
	}
	while (left<right)
	{
		mid = (right+left)/2;
		if (nums[mid]>=target)
		{
			right = mid;
		}
		else
		{
			left = mid+1;
		}
	}
	if (nums[left]==target)
	{
		return left;
	}
	return -1;
}

int lastLowerBound(vector<int>& nums,int target)
{
	int left = 0;
	int right = nums.size()-1;
	int mid = 0;
	if (right==-1)
	{
		return -1;
	}
	while (left<right)
	{
		mid = (right+left+1)/2;
		if (nums[mid]<=target)
		{
			left = mid;
		}
		else
		{
			right = mid-1;
		}
	}
	if (nums[left]==target)
	{
		return left;
	}
	return -1;
}

int upperBound(vector<int>& nums,int target)
{
	int left = 0;
	int right = nums.size()-1;
	int mid = 0;
	if (right==-1)
	{
		return -1;
	}
	while (left<right)
	{
		mid = (right+left)/2;
		if (nums[mid]<=target)
		{
			left = mid+1;
		}
		else
		{
			right = mid;
		}
	}
	if (nums[left]>target)
	{
		return left;
	}
	return -1;
}