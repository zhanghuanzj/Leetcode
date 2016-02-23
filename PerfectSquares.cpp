class Solution {
public:
	
	int numSquares(int n) {
		if(n==0) return 0;
		if (record.count(n))
		{
			return record[n];
		}
		int miniCount = INT_MAX;
		for (int i=sqrt(n);i>0;--i)
		{
			int power = i*i;
			miniCount = min(numSquares(n%power)+n/power,miniCount);
		}
		record[n] = miniCount;
		return miniCount;
	}
private:
	map<int,int> record;
};