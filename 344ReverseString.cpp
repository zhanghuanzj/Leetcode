class Solution {
public:
	string reverseString(string s) {
		int left=0;
		int right = s.size()-1;
		string temp = s;
		while (left<right)
		{
			swap(temp[left++],temp[right--]);
		}
		return temp;
	}
};