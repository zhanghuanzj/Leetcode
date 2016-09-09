class Solution {
public:
	int compareVersion(string version1, string version2) {
		int pre1=0,pre2=0,cur1=0,cur2=0;
		while (cur1<version1.size()||cur2<version2.size())
		{
			while (version1[cur1]!='.'&&cur1<version1.size()) 
			{
				++cur1;
			}
			while (version2[cur2]!='.'&&cur2<version2.size()) 
			{
				++cur2;
			}
			int v1 = 0;
			if (cur1-pre1>0)
			{
				v1 = stoi(version1.substr(pre1,cur1-pre1));
			}
			int v2 = 0;
			if (cur2-pre2>0)
			{
				v2 = stoi(version2.substr(pre2,cur2-pre2));
			}
			if (v1>v2)
			{
				return 1;
			}
			else if (v1<v2)
			{
				return -1;
			}
			pre1 = ++cur1;
			pre2 = ++cur2;
		}
		return 0;
	}
};