class Solution {
public:
    bool isAnagram(string s, string t) {
        // to check anagram we can compare the frequency character of the strings
        unordered_map<char,int> freqTable;
        for(char c: s){
            freqTable[c]++;
        }
        
        for(int i = 0; i < t.size(); i++){
            char c = t[i];
            if(freqTable.find(c) != freqTable.end()){
                freqTable[c]--;
                if(freqTable[c] == 0) freqTable.erase(c);
            } else {
                freqTable[c]++;
            }
        }
        return freqTable.empty();
    }
};