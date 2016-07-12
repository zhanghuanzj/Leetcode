class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> result;
        map<string,multiset<string>> graph;
        if (tickets.empty())
        {
        	return result;
        }
        for(auto v : tickets)
        {
        	graph[v.first].insert(v.second);
        }
        stack<string> path;
        path.push("JFK");
        while(!path.empty())
        {
        	string str = path.top();
        	if (graph[str].empty())
        	{
        		path.pop();
        		result.push_back(str);
        	}
        	else (!graph[str].empty())
        	{
        		path.push(*graph[str].begin());
        		graph[str].erase(graph[str].begin());
        	}
        }
        reverse(result.begin(), result.end());
        return result;
    }
};