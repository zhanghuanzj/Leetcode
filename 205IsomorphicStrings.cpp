class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if(s.size()!=t.size()) return false;
		map<char,char> hash;
		map<char,char> rhash;
		for(int i=0;i<s.size();++i){
			if(!hash.count(s[i])&&!rhash.count(t[i])){
				hash[s[i]] = t[i];
				rhash[t[i]] = s[i];
			}else{
				if(!hash.count(s[i])||hash[s[i]]!=t[i]){
					return false;
				}
			}
		}
		return true;
	}
};