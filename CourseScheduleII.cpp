class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> result,degree(numCourses,0);
		vector<set<int>> graph(numCourses,set<int>());
		for(int i=0;i<prerequisites.size();++i){
			if (!graph[prerequisites[i].second].count(prerequisites[i].first)){
				graph[prerequisites[i].second].insert(prerequisites[i].first);
				degree[prerequisites[i].first]++;
			}
		}
		int preSize = 0;
		while(result.size()<numCourses){
			for(int i=0;i<numCourses;++i){
				if(degree[i]==0){
					result.push_back(i);
					degree[i] = -1;
					for(auto c : graph[i]){
						degree[c]--;
					}
				}
			}
			if (preSize==result.size()){
				return vector<int>();
			}
			preSize = result.size();
		}
		return result;
	}
};