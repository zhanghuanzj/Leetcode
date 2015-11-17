struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

bool compareInterval(Interval& a,Interval& b)
{
	return a.start<b.start;
}

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> vec;
		sort(intervals.begin(),intervals.end(),compareInterval);
		for (int i=0;i<intervals.size();++i)
		{
			if (i==0)
			{
				vec.push_back(intervals[i]);
			}
			else if (vec.back().end>=intervals[i].start&&vec.back().end<intervals[i].end)
			{
				 vec.back().end = intervals[i].end;
			}
			else if(vec.back().end<intervals[i].start)
			{
				vec.push_back(intervals[i]);
			}
		}
		return vec;
	}
};