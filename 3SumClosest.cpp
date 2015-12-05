class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(),nums.end());
		int size = nums.size();
		int minNum = nums[0]+nums[1]+nums[size-1];
		for(int i=0;i<size-2;++i)
		{
			int j = i+1;
			int k = size-1;
			while(j<k)
			{
				if (abs(nums[i]+nums[j]+nums[k]-target)<abs(minNum-target)) {
					minNum = nums[i]+nums[j]+nums[k];
				}
				else if (nums[i]+nums[j]+nums[k]-target>0)
				{
					while (j<k&&nums[k]==nums[k-1])
					{
						--k;
					}
					--k;
				}
				else if (nums[i]+nums[j]+nums[k]-target<0)
				{
					while (j<k&&nums[j]==nums[j+1])
					{
						++j;
					}
					++j;
				}
				else
				{
					return minNum;
				}
			}
		}
		return minNum;
	}
};