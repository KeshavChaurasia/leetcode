class Solution {
public:
    void letterCombinations(string digits, int index, string currString, unordered_map<char,vector<char>> & digitMappings, vector<string> & results){
        if(index >= digits.size()){
            results.push_back(currString);
            return;
        }
        vector<char> currDigits = digitMappings[digits[index]];
        
        for(int i = 0; i < currDigits.size(); i++){
            letterCombinations(digits, index+1, currString+currDigits[i] , digitMappings, results);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
       if(digits.empty()) return {};
        unordered_map<char,vector<char>> digitMappings = 
           {
               {'1', {}},
               {'2', {'a','b','c'}},
               {'3', {'d','e','f'}},
               {'4', {'g','h','i'}},
               {'5', {'j','k','l'}},
               {'6', {'m','n','o'}},
               {'7', {'p','q','r','s'}},
               {'8', {'t','u','v'}},
               {'9', {'w','x','y','z'}}
           };
        vector<string> results;
        string currString = "";
        int index = 0;
        letterCombinations(digits, index, currString, digitMappings, results);
        return results;
       }
};