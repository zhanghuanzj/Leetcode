class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size()!=t.size())
		{
			return false;
		}
		else
		{
			vector<int> record(26);
			for (int i=0;i<s.size();++i)
			{
				++record[s[i]-'a'];
				--record[t[i]-'a'];
			}
			for(int v : record)
			{
				if (v!=0)
				{
					return false;
				}
			}
			return true;
		}
	}
};