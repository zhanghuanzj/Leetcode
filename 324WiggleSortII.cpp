class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp(nums);
        sort(temp.begin(),temp.end());
        int left = (nums.size()-1)/2,right = nums.size()-1;
        for(int i=0;i<temp.size();++i){
            nums[i] = i&1?temp[right--]:temp[left--];
        }
    }
};