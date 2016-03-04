class NumArray {
public:
	NumArray(vector<int> &nums) {
		record.push_back(0);
		for(int v : nums)
		{
			record.push_back(record.back()+v);
		}
	}

	int sumRange(int i, int j) {
		return record[j+1]-record[i];
	}
private:
	vector<int> record;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);