class Solution {
public:
	bool isValid(string s) {
		stack<char> record;
		for (char v : s)
		{
			if (v=='('||v=='{'||v=='[')
			{
				record.push(v);
			}
			else
			{
				if (v==')')
				{
					if (!record.empty()&&record.top()=='(')
					{
						record.pop();
					}
					else
					{
						return false;
					}
				}
				else if (v=='}')
				{
					if (!record.empty()&&record.top()=='{')
					{
						record.pop();
					}
					else
					{
						return false;
					}
				}
				else if (v==']')
				{
					if (!record.empty()&&record.top()=='[')
					{
						record.pop();
					}
					else
					{
						return false;
					}
				}
			}
		}
		return record.empty();
	}
};