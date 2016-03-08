class Solution {
public:
	string countAndSay(int n) {
		string result = "1";
		while (--n)
		{
			string temp;
			int count = 1;
			for (int i=0;i<result.length();++i)
			{
				while (result[i]==result[i+1]&&i<result.length()-1) 
				{
					count++;
					i++;
				}
				temp = temp+to_string(count)+result[i];
				count = 1;
			}
			result = temp;
		}
		return result;
	}
};