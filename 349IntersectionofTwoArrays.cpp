class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if(nums1.empty()||nums2.empty()) return result;
        set<int> record(nums1.begin(),nums1.end());
        for(auto v : nums2){
            if(!record.empty()&&record.count(v)){
                result.push_back(v);
                record.erase(v);
            }
        }
        return result;
    }
};