class Solution {
public:
	int climbStairs(int n) {
		int w1=1,w2=2,result=0;
		if (n==1)
		{
			return 1;
		}
		else if (n==2)
		{
			return 2;
		}
		else
		{
			for(int i=3;i<=n;i++)
			{
				result = w1+w2;
				w1 = w2;
				w2 = result;
			}
		}
		return result;
	}
};