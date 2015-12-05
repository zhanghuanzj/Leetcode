class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(),nums.end());
		int size = nums.size();
		for(int i=0;i<size;++i)
		{
			if (i>0&&nums[i]==nums[i-1])
			{
				continue;
			}
			int k=i+1,z=size-1;
			while(k<z)
			{
				if (nums[k]+nums[z]==-nums[i]) {
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[k]);
					temp.push_back(nums[z]);
					result.push_back(temp);
					while (k<z&&nums[k]==nums[k+1])
					{
						++k;
					}
					while(k<z&&nums[z]==nums[z-1])
					{
						--z;
					}
					k++,--z;
				}
				else if (nums[k]+nums[z]<-nums[i]) {
					k++;
				}
				else{
					--z;
				}
			}	
		}
		return result;
	}
};