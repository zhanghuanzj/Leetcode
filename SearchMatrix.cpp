class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int rows = matrix.size();
		if (rows==0)
		{
			return false;
		}
		int columns = matrix[0].size();
		if (columns==0)
		{
			return false;	
		}
		int up = 0;
		int down = rows-1;
		while(up<down)
		{
			int mid = (up+down+1)/2;
			if (matrix[mid][0]==target)
			{
				return true;
			}
			else if (matrix[mid][0]>target)
			{
				down=mid-1;
			}
			else
			{
				up=mid;
			}
		}
		int left = 0;
		int right = columns-1;
		while(left<right)
		{
			int mid = (left+right)/2;
			if (matrix[up][mid]==target)
			{
				return true;
			}
			else if (matrix[up][mid]>target)
			{
				right = mid-1;
			}
			else
			{
				left = mid+1;
			}
		}
		if (matrix[up][left]==target)
		{
			return true;
		}
		return false;
	}
};