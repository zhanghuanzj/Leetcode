class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if(record.find(input)!=record.end()) return record[input];
        vector<int> result;
        for(int i=0;i<input.size();++i){
            if(input[i]=='*'||input[i]=='+'||input[i]=='-'){
                vector<int> left = diffWaysToCompute(input.substr(0,i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                for(auto v1 : left){
                    for(auto v2 : right){
                        int value = 0;
                        switch(input[i]){
                            case '*':
                                value = v1*v2;
                                break;
                            case '+':
                                value = v1+v2;
                                break;
                            case '-':
                                value = v1-v2;
                                break;
                        }
                        result.push_back(value);
                    }
                }
            }
        }
        if(result.empty()) result.push_back(stoi(input));
        record[input] = result;
        return result;
    }
    
private:
    map<string,vector<int>> record;
};