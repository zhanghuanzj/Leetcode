class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.size()==0)
		{
			return;
		}
		k = k%nums.size();
		reverse(nums,nums.size()-k,nums.size()-1);
		reverse(nums,0,nums.size()-k-1);
		reverse(nums,0,nums.size()-1);
	}

	void reverse(vector<int>& nums,int left,int right)
	{
		while(left<right)
		{
			int temp = nums[right];
			nums[right] = nums[left];
			nums[left] = temp;
			left++;
			right--;
		}
	}
};