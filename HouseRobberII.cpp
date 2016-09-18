class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int preTake1 = 0,preNTake1 = 0;
        for(int i=0;i<(int)(nums.size()-1);++i){
            int take = preTake1;
            preTake1 = preNTake1+nums[i];
            preNTake1 = max(preNTake1,take);
        }
        int preTake2 = 0,preNTake2 = 0;
        for(int i=1;i<nums.size();++i){
            int take = preTake2;
            preTake2 = preNTake2+nums[i];
            preNTake2 = max(preNTake2,take);
        }
        return max(max(preTake1,preNTake1),max(preTake2,preNTake2));
    }
};