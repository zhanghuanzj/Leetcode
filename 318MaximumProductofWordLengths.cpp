class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result = 0;
        for(int i=0;i<words.size();++i){
            for(int j=i+1;j<words.size();++j){
                if(words[i].size()*words[j].size()>result && isFine(words[i],words[j])){
                    result = words[i].size()*words[j].size();
                }
            }
        }
        return result;
    }
    bool isFine(string s1,string s2){
        vector<int> hash(26,0);
        for(auto c : s1){
            hash[c-'a']++;
        }
        for(auto c : s2){
            if(hash[c-'a']) return false;
        }
        return true;
    }
};