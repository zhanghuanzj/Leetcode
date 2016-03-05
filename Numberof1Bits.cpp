class Solution {
public:
	int hammingWeight(uint32_t n) {
		uint32_t v = 1;
		int count = 0;
		while (n)
		{
			if (n&v)
			{
				++count;
			}
			n=n>>1;
		}
		return count;
	}
};