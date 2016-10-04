class NumArray {
public:
    NumArray(vector<int> &nums):num(nums.size()+1,0),bit(nums.size()+1,0) {
        for(int i=0;i<nums.size();++i){
            update(i,nums[i]);
        }
    }

    void update(int i, int val) {
        int index = i+1,diff = val - num[i+1];
        while(index<num.size()){
            bit[index] += diff;
            index += (index&(-index)); //补末尾1
        }
        num[i+1] = val;
    }

    int sumRange(int i, int j) {
        return getSum(j)-getSum(i-1);
    }

    int getSum(int i){
        int index = i+1,sum = 0;
        while(index){
            sum += bit[index];
            index &= index-1; //去末尾1
        }
        return sum;
    }
private:
    vector<int> num;
    vector<int> bit;
};