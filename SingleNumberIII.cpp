class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int n = 0;
		for (int x:nums)
		{
			n ^= x;
		}
		n &=-n;
		vector<int> result(2,0);
		for (int x:nums)
		{
			if (n&x)
			{
				result[0] ^= x;
			}
			else
			{
				result[1] ^= x;
			}
		}
		return result;
	}
};