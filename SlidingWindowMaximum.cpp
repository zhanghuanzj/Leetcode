class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> result;
		if(!(nums.size()>=k&&k>0)) return result;
		deque<int> dq;
		for(int i=0;i<k&&i<nums.size();++i){
			while(!dq.empty()&&nums[dq.back()]<=nums[i]){ //不为空，且元素<=当前元素
				dq.pop_back();
			}
			dq.push_back(i);
		}
		for(int i=k;i<nums.size();++i){
			result.push_back(nums[dq.front()]);
			while(!dq.empty()&&nums[dq.back()]<=nums[i]){
				dq.pop_back();
			}
			dq.push_back(i);
			if(i-dq.front()>=k) dq.pop_front();
		}
		result.push_back(nums[dq.front()]);
		return result;
	}
};