class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int result = 0;
        vector<int> height(matrix[0].size(),0);
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[i].size();++j){
                if(matrix[i][j]=='1'){
                    ++height[j];
                }else{
                    height[j] = 0;
                }
            }
            result = max(result,solve(height));
        }
        return result;
    }
    int solve(vector<int> &height){
        int square = 0;
        stack<int> s;
        for(auto h : height){
            if(s.empty()||s.top()<=h){
                s.push(h);
            }else{
                int count = 1;
                while(!s.empty()&&s.top()>h){
                    if(s.top()>=count){
                        square = max(count*count,square);
                    }
                    s.pop();
                    ++count;
                }
                while(count--){
                    s.push(h);
                }
            }
        }
        int size = 1;
        while(!s.empty()){
            if(s.top()>=size){
                square = max(square,size*size);
            }
            s.pop();
            ++size;
        }
        return square;
    }
};