class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        solve(result,path,k,n,1);
        return result;
    }
    void solve(vector<vector<int>> &result,vector<int> &path,int k,int n,int num){
        if(n==0){
            if(k==0){
                result.push_back(path);
            }
            return;
        }
        for(int i=num;i<10;++i){
            if(i<=n){
                path.push_back(i);
                solve(result,path,k-1,n-i,i+1);
                path.pop_back();
            }else{
                break;
            }
        }
    }
};