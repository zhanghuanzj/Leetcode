class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (numerator==0) return "0";
		string result;
		if (numerator<0 ^ denominator<0)
			result += "-";
		long long num = numerator,den = denominator;
		num = num<0?-num:num;
		den = den<0?-den:den;
		result += to_string(num/den);
		num = num%den;
		if (num) result += ".";
		map<int,int> record;
		int index = 0;
		while (num)
		{	
			if (record.count(num))
			{
				result.insert(result.begin()+record[num],'(');
				result += ")";
				break;
			}
			else
			{
				record[num] = result.size();
				num *= 10;
				result += (char)(num/den+'0');
				num = num%den;
			}
		}
		return result;
	}
};