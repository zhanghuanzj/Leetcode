class Solution {
public:
    Solution(vector<int> nums):origin(nums) {
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> current(origin);
        for(int i=(int)current.size()-1;i>0;--i){
            swap(current[i],current[random()%(i+1)]);
        }
        return current;
    }
private:
    vector<int> origin;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */