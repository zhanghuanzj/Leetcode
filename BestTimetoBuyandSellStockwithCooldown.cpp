 class Solution {
 public:
	 int maxProfit(vector<int>& prices) {
		 if (prices.size()<2)
		 {
			 return 0;
		 }
		 int b,b1=INT_MIN;
		 int s=0,s1=0,s2=0;
		 for (int i=0;i<prices.size();++i)
		 {
			 b = max(b1,s2-prices[i]);
			 s = max(s1,b1+prices[i]);
			 b1=b,s2=s1,s1=s;
		 }
		 return s;
	 }
 };