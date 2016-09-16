class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<set<int>> course(numCourses,set<int>());
		vector<bool> visited(numCourses,false);
		for(int i=0;i<prerequisites.size();++i){
			course[prerequisites[i].first].insert(prerequisites[i].second);
		}
		for(int i=0;i<numCourses;++i){
			if(isLoop(course,i,visited)){
				return false;
			}
		}
		return true;
	}
private:
	bool isLoop(vector<set<int>> &course,int x,vector<bool> &visited){
		if (visited[x]){
			return true;
		}
		visited[x] = true;
		for (auto i : course[x]) {
			if (isLoop(course,i,visited))
			{
				visited[x] = false;
				return true;
			}
		}
		visited[x] = false;
		return false;
	}
};