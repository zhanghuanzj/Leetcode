class Solution {
public:
	string getHint(string secret, string guess) {
		vector<int> hash(10,0);
		int bull=0,cow=0;
		for(int i=0;i<secret.size();++i){
			if(guess[i]==secret[i]){
				++bull;
			}else{
				hash[secret[i]-'0']++;
			}
		}
		for(int i=0;i<guess.size();++i){
			if(guess[i]!=secret[i]&&hash[guess[i]-'0']){
				hash[guess[i]-'0']--;
				cow++;
			}
		}
		return to_string(bull)+"A"+to_string(cow)+"B";
	}
};