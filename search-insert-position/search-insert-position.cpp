class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // check base case
        // if array is empty then target will be kept at first position
        if(nums.empty()) return 0;

        // binary search to check for target
        int leftIndex = 0;
        int rightIndex = nums.size()-1;
        
        while(leftIndex <= rightIndex){
            int midIndex = leftIndex + (rightIndex - leftIndex)/2;
            if(nums[midIndex] == target) return midIndex;
            else if (nums[midIndex] > target) rightIndex = midIndex - 1;
            else leftIndex = midIndex + 1;
        }
        return leftIndex;
    }
};