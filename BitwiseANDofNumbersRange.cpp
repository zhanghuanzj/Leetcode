class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int size = n-m+1;
		int t = 1;
		while (t+1<=size&&t<=INT_MAX/2)
		{
			t=t<<1;
		}
		return m&n&(~(t-1));
	}
};