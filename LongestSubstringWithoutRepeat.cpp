class Solution {
public:
	int lengthOfLongestSubstring(string s) 
	{
		int maxLenght = 0;           //最长非重复字串长度
		int startIndex = 0;          //每次出现重复时更新开始索引
		map<char, int> record;       //用于记录字符出现索引的映射表
		for(int i=0;i<s.size();++i)
		{
			if (record.count(s[i])>0&&record[s[i]]>=startIndex) //存在字符记录且索引不比开始索引小
			{
				maxLenght = max(maxLenght,i-startIndex);
				startIndex =record[s[i]]+1;   //出现重复字符，将开始索引更新为重复字符的后一位
			}
			record[s[i]] = i;
		}
		maxLenght = max(maxLenght,(int)s.size()-startIndex);
		return maxLenght;
	}
};