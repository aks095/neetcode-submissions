class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <int, int> m;

        int n = s.size();
        int tail = 0;
        int head = 0;
        int ans = 0;
        while(head < n){
            m[s[head]]++;
            head++;
            while(head < n && m[s[head]] == 0){
                m[s[head]]++;
                head++;
            }

            ans = max(ans, head - tail);

            while(head < n && m[s[head]] == 1){
                m[s[tail]]--;
                tail++;
            }

        }

        ans = max(head-tail, ans);

        return ans;
    }
};
