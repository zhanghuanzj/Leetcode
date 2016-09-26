class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> ugly(1,1);
		int index2 = 0,index3 = 0,index5 = 0;
		for(int i=1;i<n;++i){
			int value = min(min(ugly[index2]*2,ugly[index3]*3),ugly[index5]*5);
			ugly.push_back(value);
			while(value>=ugly[index2]*2&&index2<ugly.size()-1) ++index2;
			while(value>=ugly[index3]*3&&index3<ugly.size()-1) ++index3;
			while(value>=ugly[index5]*5&&index5<ugly.size()-1) ++index5;
		}
		return ugly.back();
	}
};