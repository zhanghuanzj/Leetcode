class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> result;
		int value;
		int temp;
		for(int i=0;i<=rowIndex;++i)
		{
			if (i==0)
			{
				result.push_back(1);
			}
			else
			{
				int size = result.size();
				for(int j=0;j<=size;++j)
				{
					if (j==0)
					{
						value = result[j];
					}
					else if(j==size)
					{
						result.push_back(value);
					}
					else
					{
						temp = result[j];
						result[j] += value;
						value = temp;
					}
				}
			}
		}
		return result;
	}
};