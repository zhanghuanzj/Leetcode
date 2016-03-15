 class Solution {
 public:
	 int calculate(string s) {
		 istringstream is('+'+s+'+');
		 char op;
		 int result=0,n,prevalue=0;
		 while (is>>op)
		 {
			 if (op=='+'||op=='-')
			 {
				 result+=prevalue;
				 is>>prevalue;
				 prevalue*=op=='+'?1:-1;
			 }
			 else
			 {
				 is>>n;
				 prevalue = op=='*'?prevalue*n:prevalue/n;
			 }
		 }
		 return result;
	 }
 };