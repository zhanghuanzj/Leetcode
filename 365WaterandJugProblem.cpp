class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        int k = gcd(x,y);
        if(z<=x+y&&(k==0||z%k==0))return true;//x=y=z=0
        return false;
    }
    int gcd(int a,int b){
        if(a<b) return gcd(b,a);
        if(b==0) return a;
        return gcd(b,a%b);
    }
};