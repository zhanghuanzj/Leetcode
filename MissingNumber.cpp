class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int misNum = 0;
        for(int i=0;i<nums.size();++i)
        {
        	misNum += (i-nums[i]); 
        }
        return misNum;
    }
};