class Solution {
public:
	int trap(vector<int>& height) {
		int poolVolume = 0;
		int size = height.size();
		for(int i=0;i<size;i++)
		{
			int count = 0;
			int threshold = height[i];
			for(int j=i+1;j<size;j++)
			{
				if (height[j]>=threshold)
				{
					poolVolume += count;
					i = j-1;
					break;
				}
				else if (height[j]<threshold)  
				{
					count += threshold-height[j];
				}
				if (j==size-1)  //The height is too high so -1
				{
					count = 0;
					threshold -= 1;
					j=i;
				}
			}
		}
		return poolVolume;
	}
};