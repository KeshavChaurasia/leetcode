class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> results(nums.size());
        // let's calculate left product
        int currProduct = 1;
        results[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            currProduct = currProduct * nums[i-1];
            results[i] = currProduct;
        }
        // let's calculate the right product and then calculate product simultaneously
        currProduct = 1;
        for(int i = nums.size()-2; i >= 0; i--){
            currProduct = currProduct * nums[i+1];
            results[i] = results[i] * currProduct;
        }
        return results;
    }
};
