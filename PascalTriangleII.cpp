class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=0;i<numRows;++i)
        {
        	vector<int> vec;
        	if (i==0)
        	{
        		vec.push_back(1);
        		result.push_back(vec);
        	}
        	else
        	{
        		for(int j=0;j<result[i-1].size();++j)
        		{
        			if (j==0)
        			{
        				vec.push_back(result[j]);
        			}
        			else if (j==result[i-1].size()-1)
        			{
        				vec.push_back(result[j]);
        			}
        			else
        			{
        				vec.push_back(result[j]+result[j-1]);
        			}
        		}
        	}
        }
        return result;
    }
};