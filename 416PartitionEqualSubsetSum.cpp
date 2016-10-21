class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int size = nums.size();
		vector<bool> dp(size*100+1,false);
		dp[0] = true;
		int sum = 0;
		for(int i=1;i<=size;++i){
			sum += nums[i-1];
			for(int j=sum;j>=nums[i-1];--j){ //避免使用现有的进行组合，所以要从大到小
				dp[j] = dp[j]||dp[j-nums[i-1]];
			}
		}
		return sum&1?false:dp[sum/2];
	}
};