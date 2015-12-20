class Solution 
{
public:
	bool isHappy(int n) 
	{
		int sum;
		set<int> origin;
		origin.insert(n);
		while (n!=1) 
		{
			int sum = 0;
			while (n) 
			{
				sum += (n%10)*(n%10);
				n /= 10;
			}
			if (origin.count(sum)) 
			{
				return false;
			}
			else
			{
				origin.insert(sum);
			}
			n = sum;
		}
		return true;
	}
};