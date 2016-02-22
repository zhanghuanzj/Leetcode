class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int i=0,j;
        while(true)
        {
            while(nums[i]!=0&&i<size)
                i++;
            j=i+1;
            while(nums[j]==0&&j<size)
                j++;
            if(i>=size||j>=size)
                break;
            nums[i]=nums[j];
            nums[j]=0;
        }
    }
};