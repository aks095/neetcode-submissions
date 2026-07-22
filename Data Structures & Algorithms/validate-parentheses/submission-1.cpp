class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(!st.empty()){
                if(s[i] == ')'){
                    if(st.top() == '(')st.pop();
                    else st.push(s[i]);
                }
                else if(s[i] == ']'){
                    if(st.top() == '[')st.pop();
                    else st.push(s[i]);
                }
                else if(s[i] == '}'){
                    if(st.top() == '{')st.pop();
                    else st.push(s[i]);
                }
                else {
                    st.push(s[i]);
                }
            }
            else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};
