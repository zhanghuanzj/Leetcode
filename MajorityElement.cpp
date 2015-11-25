class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result;
        int count;
        for(int i=0;i<nums.size();++i)
        {
        	if (count==0)
        	{
        		result = nums[i];
        		++count;
        	}
        	else if (result==nums[i])
        	{
        		++count;
        	}
        	else
        	{
        		--cont;
        	}
        }
        return result;
    }
};