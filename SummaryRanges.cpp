#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> vec;
		if (nums.size()==0)
		{
			return vec;
		}
		else
		{
			int startNum = nums[0];
			int endNum = startNum;
			for (int i = 1; i < nums.size(); ++i)
			{
				if (endNum == nums[i]-1)
				{
					endNum = nums[i];
					continue;
				}
				if (startNum==endNum)
				{
					ostringstream oss;
					oss<<startNum;
					vec.push_back(oss.str());
					endNum = nums[i];
					startNum = nums[i];
				}
				else if(startNum!=endNum)
				{
					ostringstream oss;
					oss<<startNum<<"->"<<endNum;
					vec.push_back(oss.str()); 
					endNum = nums[i];
					startNum = nums[i];
				}
			}
			if (startNum==endNum)
			{
				ostringstream oss;
				oss<<startNum;
				vec.push_back(oss.str());
			}
			else if(startNum!=endNum)
			{
				ostringstream oss;
				oss<<startNum<<"->"<<endNum;
				vec.push_back(oss.str()); 
			}
		}
		return vec;
	}
};

int main()
{
	vector<int> vec;
	Solution solution;
	while (true)
	{
		int i;
		cin>>i;
		vec.push_back(i);
		vector<string> strs = solution.summaryRanges(vec);
		for (auto val: strs)
		{
			cout<<val<<endl;
		}
	}
}