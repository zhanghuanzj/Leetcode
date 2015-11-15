class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int size = nums.size();
		if (size==0)
		{
			return 0;
		}
		int index = 0;
		bool isTwice = false;
		for(int i=1;i<size;++i)
		{
			if (nums[i]==nums[index]&&!isTwice)
			{
				isTwice = true;
				nums[++index] = nums[i];
			}
			else if (nums[i]!=nums[index])
			{
				isTwice = false;
				nums[++index] = nums[i];
			}
		}
		return index+1;
	}
};