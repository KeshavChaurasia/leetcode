class Solution {
public:
    void permute(vector<int>& nums, int start, int end, vector<vector<int>>& results){
        if(start == end) results.push_back(nums);
        for(int i = start; i < end; i++){
            swap(nums[i], nums[start]);
            permute(nums, start+1, end, results);
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0) return {};
        if(nums.size() == 1) return {nums};
        vector<vector<int>> results;
        permute(nums, 0, nums.size(), results);
        return results;
        
    }
};