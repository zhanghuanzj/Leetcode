class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int minp,maxp,value=0,size=prices.size();
        vector<int> LP(size);
        vector<int> RP(size);
        for(int i=1;i<size;++i)
        {
            if(i==1)
            {
                minp = prices[0];
                LP[0]=0;
            }
            minp = min(minp,prices[i]);
            LP[i] = max(LP[i-1],prices[i]-minp);
        }
        for(int i=size-2;i>=0;--i)
        {
            if (i==size-2) {
                maxp = prices[size-1];
                RP[size-1] = 0;
            }
            maxp = max(maxp,prices[i]);
            RP[i] = max(RP[i+1],maxp-prices[i]);
        }
        for(int i=0;i<size-1;++i)
        {
            value = max(value,LP[i]+RP[i]);
        }
        return value;
    }
};