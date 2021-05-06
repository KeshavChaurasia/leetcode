class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];

        // dp vector to store R[i] as the maximum robbery that can be perfored upto i house
        vector<int> dp(nums.size(), -1); // initialized to -1;
        // if only one house then return that
        dp[0] = nums[0];
        // if only two house then select house with maximum money
        dp[1] = max(nums[0], nums[1]);
        // for rests cases
        // we can select house i or not select house i
        // if we select house i then we can have robbery of nums[i] + R[i-2]
        // if we don't select house i then we can have robber of R[i-1]
        // basically the answer is the among these, the max robbery
        for(int i = 2; i < nums.size(); i++){
            // if i don't select this house
            int maxRobbery = dp[i-1];
            // if i select this house then
            dp[i] = max(maxRobbery, nums[i] + dp[i-2]);
        }
        return dp[nums.size()-1];
    }
};