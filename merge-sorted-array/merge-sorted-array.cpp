class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int placeIndex = n + m - 1;
        int nums1Index = m - 1;
        int nums2Index = n - 1;
        while(nums1Index >= 0 && nums2Index >= 0){
            if(nums1[nums1Index] > nums2[nums2Index]){
                nums1[placeIndex] = nums1[nums1Index];
                nums1Index--;
            } else {
                nums1[placeIndex] = nums2[nums2Index];
                nums2Index--;
            }
            placeIndex--;
        }
        while(nums2Index >= 0){
            nums1[placeIndex] = nums2[nums2Index];
            nums2Index--;
            placeIndex--;
        }
        while(nums1Index >= 0){
            nums1[placeIndex] = nums1[nums1Index];
            nums1Index--;
            placeIndex--;
        }
    }
};