class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int size = nums.size();
		if (size<2) return 0;
		int maxV = *max_element(nums.begin(),nums.end());
		int minV = *min_element(nums.begin(),nums.end());
		if (maxV==minV) return 0;
		double slotGap = (double)(maxV-minV)/(size-1);
		vector<int> slotMax(size,INT_MIN);
		vector<int> slotMin(size,INT_MAX);
		for (auto v : nums) {
			int index = (v-minV)/slotGap;
			slotMin[index] = min(v,slotMin[index]);
			slotMax[index] = max(v,slotMax[index]);
		}
		int maxGap = INT_MIN,pre = minV;
		for (int i=0;i<size;++i) {       //最大gap肯定在槽之间
			if (slotMax[i]==INT_MIN) continue;
			maxGap = max(maxGap,slotMin[i]-pre);
			pre = slotMax[i];
		}
		return maxGap;
	}
};