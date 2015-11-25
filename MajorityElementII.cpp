class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> v;
		int r1,r2;
		int count1=0,count2=0;
		for(int e:nums)
		{
			if (count1==0||e==r1)
			{
				++count1;
				r1 = e;
			}
			else if (count2==0||e==r2)
			{
				++count2;
				r2 = e;
			}
			else 
			{
				--count1;
				--count2;
			}
		}
		count1=count2=0;
		for(int e:nums)
		{
			if (e==r1)
			{
				++count1;
			}
			else if (e==r2)
			{
				++count2;
			}
		}
		if (count1>nums.size()/3)
		{
			v.push_back(r1);
		}
		if (count2>nums.size()/3)
		{
			v.push_back(r2);
		}
		return v;
	}
};