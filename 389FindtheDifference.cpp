class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> hash(26,0);
        for(auto c : s){
            hash[c-'a']++;
        }
        char result;
        for(auto c : t){
            if(hash[c-'a']==0) {
                result = c;
                break;
            }
            hash[c-'a']--;
        }
        return result;
    }
};