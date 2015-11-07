class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int plus = 1;
		for (vector<int>::reverse_iterator i = digits.rbegin(); i != digits.rend(); ++i)
		{
			*i = (*i+plus)%10;
			if (*i != 0)
			{
				plus = 0;
				break;
			}
		}
		if (plus != 0)
		{
			digits.insert(digits.begin(),1);
		}
		return digits;
	}
};