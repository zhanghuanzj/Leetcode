class Solution {
public:
	int hIndex(vector<int>& citations) {
		int h=0,count=citations.size();
		for (int i=0;i<citations.size();++i)
		{
			if (citations[i]>=count)
			{
				h = count;
				break;
			}
			--count;
		}
		return h;
	}
};