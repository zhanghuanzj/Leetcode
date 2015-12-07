bool comp(const Interval &v1,const Interval &v2)
  {
	return v1.start<v2.start;
  }

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> result;
        sort(intervals.begin(),intervals.end(),comp);
		bool flag = true;
		for(auto v : intervals)
		{
			if (flag&&newInterval.start>=v.start&&newInterval.start<=v.end)
			{
				v.end = max(newInterval.end,v.end);
				result.push_back(v);
				flag = false;
			}
			else if (flag&&newInterval.start<v.start)
			{
				if (newInterval.end<v.start)
				{
					result.push_back(newInterval);
				}
				else
				{
					v.start = newInterval.start;
					v.end = max(v.end,newInterval.end);
				}
				result.push_back(v);
				flag = false;
			}
			else if (!result.empty()&&result.back().start<=v.start&&v.start<=result.back().end)
			{
				result.back().end = max(result.back().end,v.end);
			}
			else
			{
				result.push_back(v);
			}	
		}
		if (flag)
		{
			result.push_back(newInterval);
		}
		return result;
    }
};
