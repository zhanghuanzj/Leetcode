class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int sum=0,left=0,right=0;
		int result = 0x7fffffff;
		for(int i=0;i<nums.size();++i)
		{
			sum+=nums[i];
			if (sum>=s)	
			{
				right=i;
			}
			while(sum>=s)
			{
				result = min(result,right-left+1);
				sum -= nums[left++];	
			}
		}
		if (result==0x7fffffff)
		{
			return 0;
		}
		return result;
	}
};