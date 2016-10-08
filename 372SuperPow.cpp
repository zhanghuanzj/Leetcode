class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int v = b.back();
        b.pop_back();
        return getValue(superPow(a,b),10)*getValue(a,v)%1337;
    }
    int getValue(int a,int v){
        a = a%1337;
        int result = 1;
        for(int i=0;i<v;++i){
            result = a*result%1337;
        }
        return result;
    }
    
};