class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        map<int,int> hashMap;
        for(int i=0;i<nums.size();++i)
        {
        	hashMap.insert(make_pair(nums[i],i));
        }
        for(int i=0;i<nums.size();++i)
        {
        	if (hashMap.contain(target-nums[i]))
        	{
        		vec.push_back(i+1);
        		vec.push_back(hashMap[target-nums[i]]+1);
        		return vec;
        	}
        }
        return vec;
    }
};