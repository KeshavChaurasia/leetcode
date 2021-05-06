class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // let's sort the pairs
        sort(pairs.begin(), pairs.end());
        // dp to store the maximum chain we can build for dp[i]
        vector<int> dp(pairs.size(),-1);
        // if we have only one element then 1 will be the answer
        dp[0] = 1;
        for(int i = 1; i < pairs.size();i++){
            // if we don't include the current chain
            dp[i] = dp[i-1];
            // if we include the chain then 
            for(int j = i-1; j >= 0; j--){
                // we go throught all the chains before link i and try to check with which chain it can link
                // and then get the max chain link
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            
        }
        return dp[pairs.size()-1];
    }
};