class Solution {
public:
    int countPrimes(int n) {
        vector<bool> arr(n,true);
        int result = 0;
        for(int i=2;i<n;++i){
            if(arr[i]){
                ++result;
                for(int j=2*i;j<n;j+=i){
                    arr[j] = false;
                }
            }
        }
        return result;
    }
};