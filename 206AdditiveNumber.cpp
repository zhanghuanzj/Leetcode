class Solution {
public:
	bool isAdditiveNumber(string num) {
		for(int i=1;i<=num.size()/2;++i){
			for (int j=1;j<=(num.size()-i)/2;++j) {
				if (check(num.substr(0,i),num.substr(i,j),num.substr(i+j))){
					return true;
				}
			}
		}
		return false;
	}
	bool check(string before,string pre,string remain){
		if ((before.size()>1&&before[0]=='0')||(pre.size()>1&&pre[0]=='0')){
			return false;
		}
		string result = add(before,pre);
		if (result==remain) return true;
		if (result.size()>remain.size()||result!=remain.substr(0,result.size())){
			return false;
		}else{
			return check(pre,result,remain.substr(result.size()));
		}
	}
	string add(string num1,string num2){
		string result;
		int size1 = num1.size();
		int size2 = num2.size();
		int size = 1,carry = 0;
		while (size1>=size||size2>=size||carry) {
			int v1 = size1>=size?(num1[size1-size]-'0'):0;
			int v2 = size2>=size?(num2[size2-size]-'0'):0;
			int num = v1 + v2 + carry;
			result = to_string(num%10) + result;
			carry = num/10;
			++size;
		}
		return result;
	}
};