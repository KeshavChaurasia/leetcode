class Solution {
public:
    void sortColors(vector<int>& nums) {
        // base case
        if(nums.size() == 0) return;
        
        // let's do for 0
        int placeIndex = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) {
                swap(nums[i], nums[placeIndex]);
                placeIndex++;
            }
        }
        // let's do for 1
        for(int i = placeIndex; i < nums.size(); i++){
            if(nums[i] == 1) {
                swap(nums[i], nums[placeIndex]);
                placeIndex++;
            }
        }
    }
};