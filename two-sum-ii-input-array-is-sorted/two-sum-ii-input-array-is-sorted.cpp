class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // since the answer exists we dont' need to check for the null case
        int startIndex = 0;
        int endIndex = numbers.size()-1;
        while(startIndex < endIndex){
            int currSum = numbers[startIndex] + numbers[endIndex];
            if(currSum == target) return {startIndex + 1, endIndex + 1};
            else if(currSum < target) startIndex++;
            else endIndex--;
        }
        return {-1,-1};
    }
};