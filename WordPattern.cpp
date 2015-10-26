#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		map<string,char> patternMap;
		map<char,string> patternMap2;
		int size = pattern.size();
		int stringStart = 0;
		int stringEnd = 0;
		int index = 0;
		for (int i = 0; i < size; i++)
		{
			stringStart = str.find_first_not_of(' ',index);
			stringEnd = str.find_first_of(' ',index);
			if (stringEnd==-1)
			{
				stringEnd = str.size()+1;
				//str中数量少
				if (i!=size-1)
				{
					return false;
				}
			}
			if (patternMap.find(str.substr(stringStart,stringEnd-stringStart))==patternMap.end()&&
				patternMap2.find(pattern[i])==patternMap2.end())
			{
				patternMap.insert(pair<string,char>(str.substr(stringStart,stringEnd-stringStart),pattern[i]));
				patternMap2.insert(pair<char,string>(pattern[i],str.substr(stringStart,stringEnd-stringStart)));
			}
			else if (patternMap[str.substr(stringStart,stringEnd-stringStart)] != pattern[i]||
					 patternMap2[pattern[i]]!=str.substr(stringStart,stringEnd-stringStart))
			{
				return false;
			}
			index = stringEnd+1;
		}
		//或者str中数量多
		if (stringEnd!=str.size()+1)
		{
			return false;
		}
		return true;
	}
};

int main()
{
	Solution solution;

	cout<<boolalpha<<solution.wordPattern("abba","dog cat cat fish");
	while (true)
	{

	}
}