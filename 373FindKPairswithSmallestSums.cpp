class Compare{
public:
	bool operator()(const pair<int,int> &p1,const pair<int,int> &p2)const{
		return p1.first+p1.second<p2.first+p2.second;
	}
};

class Solution {
public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
		for (int i=0;i<min<int>(k,nums1.size());++i) {
			for (int j=0;j<min<int>(k,nums2.size());++j) {
				pq.push(make_pair(nums1[i],nums2[j]));
				if (pq.size()>k){
					pq.pop();
				}
			}
		}
		vector<pair<int,int>> result;
		while (!pq.empty()){
			result.push_back(pq.top());
			pq.pop();
		}
		return result;
	}
};