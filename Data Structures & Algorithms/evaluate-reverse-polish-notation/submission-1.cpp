class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;

        for(int i = 0; i < tokens.size(); i++){
            if((tokens[i] != "+") && (tokens[i] != "-") && (tokens[i] != "*") && (tokens[i] != "/") ){
                int x = stoi(tokens[i]);
                st.push(x);
            }
            else {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();

                if(tokens[i] == "-"){
                    st.push(-x+y);
                }
                else if(tokens[i] == "+"){
                    st.push(x+y);
                }
                else if(tokens[i] == "*"){
                    st.push(x*y);
                }
                else{
                    st.push(y/x);
                }
            }
        }

        return st.top();
    }
};
