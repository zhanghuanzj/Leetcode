 class Solution {
 public:
	 vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		 vector<int> result;
		 map<int,set<int>> record;
		 for (int i=0;i<n;++i)
		 {
			 record.insert(make_pair(i,set<int>()));
		 }
		 for (auto p:edges)
		 {
			 record[p.first].insert(p.second);
			 record[p.second].insert(p.first);
		 }
		 vector<int> degree(n);
		 for (int i=0;i<n;++i)
		 {
			 degree[i] = record[i].size();              //degree record
		 }
		 int remain = n;
		 while (remain>2)
		 {
			 set<int> deleteNodes;
			 for (int i=0;i<n;++i)
			 {
				 if (degree[i]==1)                     //find the degree==1 node
				 {
					 remain--;
					 degree[i]=-1;
					 deleteNodes.insert(i);
				 }
			 }
			 for (int x:deleteNodes)                  //update the remain nodes degree
			 {
				 for (int y:record[x])
				 {
					 degree[y]--;
				 }
			 }
		 }
		 for (int i=0;i<n;++i)
		 {
			 if (degree[i]>=0)
			 {
				 result.push_back(i);
			 }
		 }
		 return result;
	 }
 };