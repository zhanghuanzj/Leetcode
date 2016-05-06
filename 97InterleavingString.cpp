class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s3.size()!=s1.size()+s2.size())
		{
			return false;
		}
		vector<vector<bool>> dp(s1.size()+1,vector<bool>(s2.size()+1, false));
		dp[0][0] = true;
		for (int i = 1; i <= s1.size()+s2.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				int m = j;
				int n = i-j-1;
				if (m<=s1.size()&&n<=s2.size()&&dp[j][i-1-j])
				{
					if (m<s1.size()&&s1[m]==s3[i-1])
					{
						dp[m+1][n] = true;
					}
					if (n<s2.size()&&s2[n]==s3[i-1])
					{
						dp[m][n+1] = true;
					}
				}
			}
		}
		return dp[s1.size()][s2.size()];
	}
};