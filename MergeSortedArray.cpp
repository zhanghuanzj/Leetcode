class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int index = n+m-1;
		while(m>0&&n>0)
		{
			if (nums1[m-1]>=nums2[n-1])
			{
				nums1[index--]=nums1[(m--)-1];
			}
			else
			{
				nums1[index--]=nums2[(n--)-1];
			}
		}
		while(m>0)
		{
			nums1[index--]=nums1[(m--)-1];
		}
		while(n>0)
		{
			nums1[index--]=nums2[(n--)-1];
		}
	}
};