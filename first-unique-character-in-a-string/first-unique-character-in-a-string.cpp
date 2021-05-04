class Solution {
public:
    // constraints
    // non-repeating
    // return it's index
    
    // naive approach
    // put everything in a hashmap as character frequency table
    // iterate over the character in string
    // if the character in hash map has frequency 1 then return
    // else -1;
    // time --> O(N) | space --> O(n)
    
    int firstUniqChar(string s) {
        int hash[26] = {0};
        for(char c: s){
            hash[c - 'a']++;
        }
        for(int i = 0; i < (int)s.size(); i++){
            if(hash[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};