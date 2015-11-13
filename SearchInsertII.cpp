class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if (nums[mid]==target)
            {
                return mid;
            }
            else if (nums[mid]>target)
            {
                if (nums[left]>target&&nums[mid]>=nums[left])
                {
                    left = mid+1;
                }
                else if(nums[left]<=target)
                {
                    right = mid-1;
                }
                else if (nums[mid]<nums[left])
                {
                    right = mid-1;
                }
            }
            else
            {
                if (nums[left]<=nums[mid])
                {
                    left = mid+1;
                }
                else if (nums[left]<=target&&nums[left]>nums[mid])
                {
                    right = mid-1;
                }
                else if (nums[left]>target)
                {
                    left = mid+1;
                }
            }
        }
        return -1;
    }
};