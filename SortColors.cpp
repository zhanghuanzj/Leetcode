class Solution {
public:
	void sortColors(vector<int>& nums) {
		int color[3] = {0,0,0};
		for(auto var : nums)
		{
			color[var]++;
		}
		int index = 0;
		for(int i=0;i<3;++i)
		{
			while(color[i]--)
			{
				nums[index++]=i;
			}
		}
	}
};