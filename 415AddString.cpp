class Solution {
public:
    string addStrings(string num1, string num2) {
        int size = max(num1.size(),num2.size());
        int carry = 0,index = 1;
        string result;
        while(index<=size||carry){
            int a = index<=num1.size()?num1[num1.size()-index]-'0':0;
            int b = index<=num2.size()?num2[num2.size()-index]-'0':0;
            int sum = a+b+carry;
            result = (char)('0'+sum%10)+result;
            carry = sum/10;
            ++index;
        }
        return result;
    }
};