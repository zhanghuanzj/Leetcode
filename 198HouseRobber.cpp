class Solution {
public:
    int rob(vector<int>& nums) {
        int preTake = 0, preNTake = 0;
        for(auto n : nums){
            int money = preTake;
            preTake = preNTake + n;  //只能在前面没偷的基础上进行
            preNTake = max(money,preNTake);
        }
        return max(preTake,preNTake);
    }
};