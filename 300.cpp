class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> record;
		for (int i=0;i<nums.size();++i)
		{
			if (record.empty()||nums[i]>record.back())
			{
				record.push_back(nums[i]);
			}
			else if (record.size()==1&&record[0]>nums[i])
			{
				record[0] = nums[i];
			}
			else
			{
				int index = search(record,nums[i]);
				if (index!=-1)
				{
					record[index+1] = nums[i];
				}
			}	
		}
		return record.size();
	}
	int search(vector<int> &v,int x)
	{
		int l=0,r=v.size()-1;
		while (l<r)
		{
			int mid = (l+r+1)/2;
			if (v[mid]<=x)
			{
				l = mid;
			}
			else
			{
				r = mid-1;
			}
		}
		if (l==r&&v[l]<x)
		{
			return l;
		}
		return -1;
	}
};