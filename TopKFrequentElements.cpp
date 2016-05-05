class Solution {
public:

	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int,int> record;
		for (auto v: nums)
		{
			++record[v];
		}
		vector<int> result;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> kHeap;
		for (auto it=record.begin();it!=record.end();++it)
		{
			kHeap.push(make_pair(it->second,it->first));
			if (kHeap.size()>k)
			{
				kHeap.pop();
			}
		}
		while (!kHeap.empty())
		{
			result.push_back(kHeap.top().second);
			kHeap.pop();
		}
		reverse(result.begin(),result.end());
		return result;
	}
};