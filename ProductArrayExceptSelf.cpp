class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> vec(nums.begin(),nums.end());
		for(int i=nums.size()-2;i>=0;--i)
		{
			vec[i] *= vec[i+1];
		}
		int value = 1;
		for(int i=1;i<=nums.size();++i)
		{
			if (i==nums.size())
			{
				vec[i-1] = value;
				break;
			}
			vec[i-1] = vec[i]*value;
			value *= nums[i-1];
		}
		return vec;
	}
};