class Solution {
public:
    bool validSubstring(string s){
        int counts[26] = {0};
        for(char c: s){
            if(counts[c - 'a']++ > 0) return false;
        }
        return true;
    }
    void maxLengthHelper(vector<string> & arr, string s, int index, int & maxLength){
        if(index >= arr.size()){
            if(validSubstring(s)){
                maxLength = max(maxLength, (int)s.length());
            }
            return;
            
        }
        // excluding the current string
        maxLengthHelper(arr,s, index + 1, maxLength);
        // including the current string
        maxLengthHelper(arr,s + arr[index], index + 1, maxLength);
        
    }
    int maxLength(vector<string>& arr) {
        string s = "";
        int index = 0;
        int maxUnique = 0;
        maxLengthHelper(arr, s, index, maxUnique);
        return maxUnique;
    }
};