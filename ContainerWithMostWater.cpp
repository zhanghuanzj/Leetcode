class Solution {
public:
	int maxArea(vector<int>& height) {
		int h = 0,maxWater = 0;
		int left = 0,right = height.size()-1;
		while(left<right)
		{
			h = min(height[left],height[right]);
			maxWater = max(maxWater,(right-left)*h);
			while (height[left]<=h&&left<right)
			{
				++left;
			}
			while (height[right]<=h&&left<right)
			{
				--right;
			}
		}
		return maxWater;
	}
};