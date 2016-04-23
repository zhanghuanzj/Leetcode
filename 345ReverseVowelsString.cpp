class Solution {
public:
	bool isVowel(char c)
	{
		if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return true;
		return false;
	}
	string reverseVowels(string s) {
		int left=0,right=s.size()-1;
		while(true)
		{
			while(left<s.size()&&!isVowel(s[left])) left++;
			while(right>=0&&!isVowel(s[right])) right--;
			if (left<right)
			{
				swap(s[left++],s[right--]);
			}
			else
			{
				break;
			}
		}
		return s;
	}
};