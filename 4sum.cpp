class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		set<vector<int>> result;
		sort(nums.begin(),nums.end());
		int size = nums.size();
		map<int,int> hash;
		for(int i=0;i<size;++i)
		{
			hash[nums[i]] = i;
		}
		for(int i=0;i<size;++i)
		{
			for(int j=i+1;j<size;++j)
			{
				int k=j+1,z=size-1;
				while(k<z)
				{
					if (nums[k]+nums[z]==target-nums[i]-nums[j]) {
						vector<int> temp;
						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						temp.push_back(nums[k]);
						temp.push_back(nums[z]);
						result.insert(temp);
						k++,--z;
					}
					else if (nums[k]+nums[z]<target-nums[i]-nums[j]) {
						k++;
					}
					else{
						--z;
					}
				}
			}
		}
		vector<vector<int>> value;
		for(auto v:result)
		{
			value.push_back(v);
		}
		return value;
	}
};