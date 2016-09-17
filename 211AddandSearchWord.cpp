class TrieNode{
public:
	TrieNode():hash(26,nullptr),isEnd(false){}
	vector<TrieNode*> hash;
	bool isEnd;
};
class WordDictionary {
public:
	WordDictionary(){root = new TrieNode();}
	// Adds a word into the data structure.
	void addWord(string word) {
		TrieNode *p = root;
		for(int i=0;i<word.size();++i){
			int index = word[i]-'a';
			if(p->hash[index]==nullptr){
				p->hash[index] = new TrieNode();
			}
			p = p->hash[index];
		}
		p->isEnd = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return query(word,root);
	}
	bool query(string word,TrieNode *p){
		for(int i=0;i<word.size();++i){
			if(word[i]!='.'){
				int index = word[i]-'a';
				if(p->hash[index]==nullptr){
					return false;
				}
				p = p->hash[index];
			}else{
				string sub = word.substr(i+1);
				for(int j=0;j<26;++j){
					if(p->hash[j]&&query(sub,p->hash[j])){
						return true;
					}
				}
				return false;
			}
		}
		return p->isEnd==true;
	}
	TrieNode *root;
};