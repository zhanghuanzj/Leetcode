class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size()==0)
		{
			return 0;
		}
		int preIndex = 0;
		for(int postIndex = 1;postIndex<nums.size();++postIndex)
		{
			if (nums[postIndex]!=nums[preIndex])
			{
				nums[++preIndex] = nums[postIndex];
			}
		}
		return preIndex+1;
	}
};