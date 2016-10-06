class Solution {
public:
    bool isPerfectSquare(int num) {
        int x = sqrt(num);
        return x*x==num;
    }
    int sqrt(int num){
        double x = num,x0 = num;
        do{
            x = x0;
            x0 = (x+num/x)/2;
        }while(abs(x-x0)>0.1);
        return x;
    }
};