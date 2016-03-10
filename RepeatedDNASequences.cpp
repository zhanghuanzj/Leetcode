class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		map<string,int> record;
		int size = s.length();
		for (int i=0;i<size-9;++i)
		{
			if (record.count(s.substr(i,10))==0)
			{
				record.insert(make_pair(s.substr(i,10),1));
			}
			else{
				record[s.substr(i,10)]++;
			}
		}
		for (auto v : record)
		{
			if (v.second>1)
			{
				result.push_back(v.first);
			}
		}
		return result;
	}
};