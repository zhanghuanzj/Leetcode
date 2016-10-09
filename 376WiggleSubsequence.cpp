class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int index = 1;
        while(index<nums.size()-1&&nums[index-1]==nums[index]){
            ++index;
        }
        if(nums[index]==nums[index-1]) return 1;
        bool small = nums[index]>nums[index-1];
        int count = 2;
        for(int i=index+1;i<nums.size();++i){
            if((nums[i]>nums[index]&&!small)||(nums[i]<nums[index]&&small)){
                ++count;
                small = !small;
            }
            index = i;
        }
        return count;
    }
};