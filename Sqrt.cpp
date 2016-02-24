class Solution {
public:
	int mySqrt(int x) {
		if (x==0)
		{
			return 0;
		}
		double last;
		double value = x;
		do 
		{
			last = value;
			value = (last+x/last)/2;
		} while (abs(value-last)>0.1);
		return value;
	}
};