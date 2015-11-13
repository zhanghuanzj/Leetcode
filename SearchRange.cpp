class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result(2,-1);
		if (nums.size()==0)
		{
			return result;
		}
		int left1,left2;
		int right1,right2;
		left1=left2=0;
		right1=right2=nums.size()-1;
		while(left1<right1)
		{
			int mid = (left1+right1)/2;
			if (nums[mid]>=target)
			{
				right1 = mid;
			}
			else
			{
				left1 = mid+1;
			}
		}
		while(left2<right2)
		{
			int mid = (left2+right2+1)/2;
			if (nums[mid]<=target)
			{
				left2 = mid;
			}
			else
			{
				right2 = mid-1;
			}
		}
		if (nums[left1]==target&&target==nums[left2])
		{
			result[0]=left1;
			result[1]=left2;
		}
		return result;
	}
};