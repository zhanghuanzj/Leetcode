class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> record;
        for(auto v : nums1){
            record[v]++;
        }
        vector<int> result;
        for(auto v : nums2){
            if(record[v]){
                record[v]--;
                result.push_back(v);
            }
        }
        return result;
    }
};