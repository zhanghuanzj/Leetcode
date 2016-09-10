class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2,1);
        int left = 0,right = numbers.size()-1;
        while(numbers[left]+numbers[right]!=target){
            if(numbers[left]+numbers[right]<target){
                ++left;
            }else{
                --right;
            }
        }
        result[0] = left+1;
        result[1] = right+1;
        return result;
    }
};