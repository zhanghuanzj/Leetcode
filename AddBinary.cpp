class Solution {
public:
	string addBinary(string a, string b) {
		string result;
		size_t al = a.length();
		size_t bl = b.length();
		size_t index = 1;
		size_t c = 0;
		while (index<=al||index<=bl||c==1)
		{
			c += index<=al?a[al-index]-'0':0;
			c += index<=bl?b[bl-index]-'0':0;
			result = c&1?'1'+result:'0'+result;
			c = c/2;
			index++;
		}
		return result;
	}
};