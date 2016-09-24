class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0) return 0;
        long long count = 0;
        long long d = 1;
        while(n/d){
            long long left = n/(d*10);
            long long cur = n/d-left*10;
            long long right = n%d;
            if(cur==0){
                count += left*d;
            }else if(cur==1){
                count += left*d+right+1;
            }else{
                count += (left+1)*d;
            }
            d *= 10;
        }
        return count;
    }
};