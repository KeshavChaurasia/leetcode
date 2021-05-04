class Solution {
public:
    // naive approach
    // 1. get all substrings --> O(N^2)
    // 2. for all substrings if valid substring with unqiue character (O(N)) check of max length
    // O(N^2)
    
    // this can be solved more efficiently with windowing technique
    // we start from first character and then 
    // increase our window. for each character found,
    // if not in hash map, we increase our window, else we decrease our window from left
    int lengthOfLongestSubstring(string s) {
        // base case
        if(s.empty()) return 0;

        int maxLength = INT_MIN;
        int windowStart = 0;
        unordered_set<char> hash;
        for(int windowEnd = 0; windowEnd < (int)s.length(); windowEnd++){
            char rightChar = s[windowEnd];
            while(hash.find(rightChar) != hash.end()){
                char leftChar = s[windowStart];
                hash.erase(leftChar);
                windowStart++;
            }
            hash.insert(rightChar);
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }
        return maxLength;
        
    }
};