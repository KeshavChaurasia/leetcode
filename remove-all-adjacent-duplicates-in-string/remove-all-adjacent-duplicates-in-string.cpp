class Solution {
public:
    string removeDuplicates(string S) {
        string uniqueString = "";
        stack<char> st;
        for(char c : S){
            if(!st.empty() && st.top() == c){
                st.pop();
            } else {
                st.push(c);
            }
        }
        while(!st.empty()){
            uniqueString = st.top() + uniqueString;
            st.pop();
        }
        
        return uniqueString;
    }
};