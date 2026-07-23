class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue <pair<int, float>> st;

        int n = position.size();

        for(int i = 0; i < n; i++){
            st.push({position[i], (target - position[i])/(1.0*speed[i])});
        }

        float mn = st.top().second;
        cout << st.top().second << " ";
        st.pop();

        int ans = 1;

        while(!st.empty()){
            cout << st.top().second;
            if(st.top().second <= mn){
                st.pop();
            }
            else {
                ans++;
                mn = st.top().second;
                st.pop();
            }
        }

        return ans;
    }
};
