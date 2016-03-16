 class Solution {
 public:
	 bool isPowerOfThree(int n) {
		 double var = log10(n)/log10(3);
		 cout<<var<<endl;
		 if (n>0)
		 {
			 return n==1||var-(int)(var)==0;
		 }
		 return false;
	 }
 };