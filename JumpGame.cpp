class Solution {
public:
	bool canJump(vector<int>& nums) {
		int maxIndex = 0;
		int size = nums.size();
		for(int i=0;i<size;++i)
		{
			maxIndex = max(maxIndex,nums[i]+i);
			if ((i<size-1&&maxIndex>=size-1)||size==1)
			{
				return true;
			}
			if (maxIndex==i)
			{
				return false;
			}
		}
		return false;
	}
};