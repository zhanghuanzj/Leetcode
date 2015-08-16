/*设自然数N=a[n]a[n-1]…a[0]=a[n]*10^n+a[n-1]*10^(n-1)+…+a[1]*10+a[0].
 *再设M=a[0]+a[1]+…+a[n]
 *∵10≡1(mod 9)  nm%9=((n%9)*(m%9))%9
 *∴10*10≡1(mod 9) ...
 *∴N=M(mod 9)
 */

class Solution {
public:
    int addDigits(int num) {
        return 1+(num-1)%9;
    }
};