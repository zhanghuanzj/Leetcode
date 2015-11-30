class Solution {
public:
	int jump(vector<int>& nums) {
		int maxIndex = 0,nextIndex = 0,step = 0;
		int size = nums.size();
		for(int i=0;i<size;++i)
		{
			if (maxIndex<i)
			{
				maxIndex = nextIndex;
				++step;
			}
			nextIndex = max(nextIndex,nums[i]+i);
			if (i<size-1&&nextIndex>=size-1)
			{
				return step+1;
			}
			else if (size==1)
			{
				return step;
			}
		}
	}
};