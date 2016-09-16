class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return solve(nums,0,nums.size()-1,k);
    }
    int solve(vector<int> &nums,int left,int right,int k){
        int v = nums[left];
        int i = left;
        for(int j=i+1;j<=right;++j){
            if(nums[j]>v){
                swap(nums[++i],nums[j]);
            }
        }
        swap(nums[left],nums[i]);
        int count = i-left+1;
        if(count==k) {
            return nums[i];
        }else if(count<k){
            return solve(nums,i+1,right,k-count);
        }else{
            return solve(nums,left,i-1,k);
        }
    }
};