class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int temp = a^b;
            b = (a&b)<<1;
            a = temp;
        }
        return a;
    }
};