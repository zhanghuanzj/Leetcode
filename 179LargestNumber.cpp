bool compare(string &s1,string &s2){
    return s1+s2>s2+s1;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> number;
        for(int i=0;i<nums.size();++i){
            number.push_back(to_string(nums[i]));
        }
        sort(number.begin(),number.end(),compare);
        string result;
        for(int i=0;i<number.size();++i){
            result += number[i];
        }
        return result[0]=='0'?"0":result;
    }
};