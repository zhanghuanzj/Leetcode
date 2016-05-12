class Solution {
public:
	int minPatches(vector<int>& nums, int n) {
		int count = 0;
		int sum = 0;
		int index = 0;
		while (sum<n)
		{
			if (index<nums.size()&&nums[index]<=sum+1)
			{
				sum += nums[index++];
			}
			else
			{
				if (sum<=(INT_MAX-1)/2)
				{
					sum = sum*2+1;
				}
				else
				{
					sum = INT_MAX;
				}
				++count;
			}
		}
		return count;
	}
};