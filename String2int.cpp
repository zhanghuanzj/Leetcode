class Solution {
public:
	int myAtoi(string str) {
		long var = 0;
		bool first = true;
		int multi_var = 1;
		for (auto v: str)
		{
			if (first&&v==' ')
			{
				continue;
			}
			else if (first&&v=='-')
			{
				multi_var = -1;
			}
			else if (first&&v=='+')
			{
			}
			else if (v>='0'&&v<='9')
			{
				var = var*10+v-'0';
				if (var*multi_var>=INT_MAX||var*multi_var<=INT_MIN)
				{
					return multi_var==1?INT_MAX:INT_MIN;
				}
			}
			else 
			{
				break;
			}
			first = false;
		}
		return multi_var*var;
	}
};