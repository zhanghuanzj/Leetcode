class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0],right = matrix.back().back();
        while(left<right){
            int count = 0,mid = (left+right)/2;
            for(int i=0;i<matrix.size();++i){
                count += upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            if(count<k) left = mid+1; //少于目标个数，猜测太小需要增大
            else right = mid; //不断逼近
        }
        return left;
    }
};