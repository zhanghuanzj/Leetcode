class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> result;
        if(nums.empty()) return result;
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int> dp(nums.size(),1);
        vector<int> parent(nums.size(),-1);
        int index = 0;
        for(int i=1;i<nums.size();++i){
            for(int j=0;j<i;++j){
                if(nums[j]%nums[i]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i] = dp[j]+1;
                        parent[i] = j;
                    }
                    if(dp[i]>dp[index]) index = i;
                }
            }
        }
        while(index!=-1){
			result.push_back(nums[index]);
			index = parent[index];
		}
        return result;
    }
};