class Solution {
public:
    bool validPalindrome(string s) {
        int startIndex = 0;
        int endIndex = s.size()-1;
        while(startIndex < endIndex){
            if(s[startIndex] != s[endIndex]){
                return validPalindromeHelper(s, startIndex+1, endIndex) 
                    || validPalindromeHelper(s, startIndex, endIndex-1);
            }
            startIndex++;
            endIndex--;
        }
        return true;
    }
    
    bool validPalindromeHelper(string & s, int startIndex, int endIndex){
        while(startIndex < endIndex){
            if(s[startIndex] != s[endIndex]) return false;
            startIndex++;
            endIndex--;
        }
        return true;
    }
};