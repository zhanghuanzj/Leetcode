class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int miniPrice = INT_MAX;
        int maxprofit = 0;
        for(int i=0;i<prices.size();++i)
        {
          miniPrice = min(miniPrice,prices[i]);
          maxprofit = max(maxprofit,prices[i]-miniPrice);
        }
        return maxprofit;
    }
};