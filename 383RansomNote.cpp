class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash(26,0);
        for(auto c : magazine){
            hash[c-'a']++;
        }
        for(auto c : ransomNote){
            hash[c-'a']--;
            if(hash[c-'a']<0) return false;
        }
        return true;
    }
};