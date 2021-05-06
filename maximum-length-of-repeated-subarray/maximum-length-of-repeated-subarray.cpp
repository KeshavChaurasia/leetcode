class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // if any vector is empty simply return 0
        if(nums1.empty() || nums2.empty()) return 0;
        
        int n = nums1.size();
        int m = nums2.size();
        int maxLength = INT_MIN;
        // 2D  dp vector initialized to 0
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(nums1[i-1] == nums2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                maxLength = max(maxLength, dp[i][j]);
            }
        }
        
        return maxLength;
    }
};