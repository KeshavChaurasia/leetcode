class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i = 0; i < nums.size(); i++){
            int potentialMatch = target - nums[i];
            if(hash.find(potentialMatch) != hash.end()){
                return {hash[potentialMatch], i};
            }
            hash[nums[i]] = i;
        }
        return {-1,-1};
    }
};