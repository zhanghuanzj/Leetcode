class Solution {
public:
	void reverseWords(string &s) {
		int index = 0;
		bool hasSpace = false;
		for (int i=0;i<s.size();++i) {
			if (s[i]==' '){
				if (!hasSpace){
					s[index++] = s[i];
				}
				hasSpace = true;
			}
			else{
				s[index++] = s[i];
				hasSpace = false;
			}
		}
		s = s.substr(0,index)+" ";
		int left = 0;
		for(int right=0;right<s.size();++right){
			if(s[right]==' ') {
				reverse(s.begin()+left,s.begin()+right);
				left = right+1;
			}
		}
		int first = s.find_first_not_of(' ');
		if (first==-1){
			s = "";
			return;
		}
		int last = s.find_last_not_of(' ');
		if(last>=first) s = s.substr(first,last-first+1);
		reverse(s.begin(),s.end());
	}
};