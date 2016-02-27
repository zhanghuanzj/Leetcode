class Solution {
public:
	int hIndex(vector<int>& citations) {
		int h=0,count=1;
		sort(citations.begin(),citations.end());
		for (int i=citations.size()-1;i>0;--i)
		{
			if (citations[i]>=count&&citations[i-1]<=count)
			{
				h = count;
			}
			++count;
		}
		if (citations.size()>0&&citations[0]>=citations.size())
		{
			h = citations.size();
		}
		return h;
	}
};