/**
*1.分层建立单词变迁图，下一层与上一层单词差一个字母（存储的时候实则为反向）
*2.通过endWord进行BFS搜索
**/
class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
		unordered_set<string> cur;                      //当前层节点
		unordered_set<string> next;                     //下一层节点
		map<string,unordered_set<string>> paths;        //图（邻接表） 
		vector<vector<string>> result;
		cur.insert(beginWord);
		unordered_set<string> words = wordList;
		words.insert(endWord);
		while (cur.size())
		{
			for (string v : cur)
			{
				for (int i=0;i<v.size();++i)
				{
					for (int j=0;j<26;++j)
					{
						string temp = v;
						temp[i] = 'a'+j;
						if (words.count(temp)>0)
						{
							next.insert(temp);
							paths[temp].insert(v);
						}
					}
				}
			}
			cur = next;
			next.clear();
			bool isReach = false;
			for(string x : cur)
			{
				words.erase(x);
				if (x==endWord)      //找到目标单词，建图完成
				{
					isReach = true;
				}
			}
			if (isReach)
			{
				break;
			}
		}
		vector<string> path;
		find_path(paths,endWord,beginWord,result,path);
		for(vector<string>& p : result)
		{
			reverse(p.begin(),p.end());
		}
		return result;
 	}

	void find_path(map<string,unordered_set<string>> &paths,string start,string end,vector<vector<string>>& result,vector<string> path)
	{
		path.push_back(start);
		if (start==end)
		{
			result.push_back(path);
			return ;
		}
		for (string v : paths[start])
		{
			find_path(paths,v,end,result,path);
		}
		path.pop_back();
	}
};
