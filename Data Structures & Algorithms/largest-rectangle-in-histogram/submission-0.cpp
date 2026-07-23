class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <pair<int, int>> st;
        int n = heights.size();
        vector <int> prev(n), nxt(n);

        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push({heights[i], i});
            }
            else {
                while(!st.empty()){
                    if(st.top().first > heights[i]){
                        nxt[st.top().second] = i;
                        st.pop();
                    }
                    else break;
                }
                st.push({heights[i], i});
            }
        }
        
        while(!st.empty()){
            nxt[st.top().second] = n;
            st.pop();
        }

        for(int i = n-1; i >= 0; i--){
            if(st.empty()){
                st.push({heights[i], i});
            }
            else {
                while(!st.empty()){
                    if(st.top().first > heights[i]){
                        prev[st.top().second] = i;
                        st.pop();
                    }
                    else break;
                }
                st.push({heights[i], i});
            }
        }
        while(!st.empty()){
            prev[st.top().second] = -1;
            st.pop();
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max( heights[i]*(nxt[i] - prev[i] - 1), ans);
        }

        return ans;
    }
};
