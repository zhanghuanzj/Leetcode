/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node==nullptr)
		{
			return nullptr;
		}
		else if (nodes.count(node->label))
		{
			return nodes[node->label];
		}
		UndirectedGraphNode *result = new UndirectedGraphNode(node->label);
		nodes.insert(make_pair(node->label,result));
		int size = node->neighbors.size();
		for (int i=0;i<size;++i)
		{
			result->neighbors.push_back(cloneGraph(node->neighbors[i]));
		}
		return result;
    }
private:
	map<int,UndirectedGraphNode*> nodes;
};