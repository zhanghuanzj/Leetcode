class Solution {
public:
	int largestRectangleArea(vector<int>& height) {
		stack<int,vector<int>> record;
		int result = 0;
		record.push(0);
		for(auto v : height)
		{
			int count = 1;
			while (v<record.top()) 
			{
				result = max(result,record.top()*count);
				++count;
				record.pop();
			}
			while(count)
			{
				--count;
				record.push(v);
			}
		}
		int count = 1;
		while (record.size()) 
		{
			result = max(result,record.top()*count);
			++count;
			record.pop();
		}
		return result;
	}
};