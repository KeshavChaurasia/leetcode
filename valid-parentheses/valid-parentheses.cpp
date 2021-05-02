class Solution {
public:
    bool isOpeningOf(char c, char a){
        return (
            (c == '(' && a == ')') ||
            (c == '{' && a == '}') ||
            (c == '[' && a == ']')
        );
    }
    bool isValid(string s) {
       stack<char> st;
        for(char c: s){
            if(!st.empty() && isOpeningOf(st.top(), c)) st.pop();
            else st.push(c);
        }
        return st.empty();
    }
};