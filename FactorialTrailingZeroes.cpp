 class Solution {
 public:
	 int trailingZeroes(int n) {
		 int zeroes = 0;
		 for (int i=1;pow(5,i)<=n;++i)
		 {
			 zeroes += n/pow(5,i);
		 }
		 return zeroes;
	 }
 };