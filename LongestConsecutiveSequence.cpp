class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		map<int,int> consecutiveCount;
		int result = 0;
		for(int i=0;i<nums.size();++i)
		{
			if (consecutiveCount.count(nums[i])==0)
			{
				int left = consecutiveCount.count(nums[i]-1)>0?consecutiveCount[nums[i]-1]:0;
				int right = consecutiveCount.count(nums[i]+1)>0?consecutiveCount[nums[i]+1]:0;
				int sum = left+right+1;
				result = max(result,sum);
				consecutiveCount.insert(make_pair(nums[i],sum));
				consecutiveCount[nums[i]-left] = sum;
				consecutiveCount[nums[i]+right] = sum;
			}
		}
		return result;
	}
};