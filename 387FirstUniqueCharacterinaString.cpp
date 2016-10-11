class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> hash(26,-1);
		for(int i=0;i<s.size();++i){
			int index = s[i]-'a';
			if(hash[index]==-1){
				hash[index]=i;
			}else if(hash[index]>=0){
				hash[index] = -2;
			}
		}
		int result = INT_MAX;
		for(int i=0;i<hash.size();++i){
			if(hash[i]>=0) result = min(hash[i],result);
		}
		return result==INT_MAX?-1:result;
	}
};