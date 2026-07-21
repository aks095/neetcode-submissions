class Solution {
public:
    bool valid(vector<int>& need, vector<int>& window) {
        for (int i = 0; i < 52; i++) {
            if (window[i] < need[i]) return false;
        }
        return true;
    }

    int idx(char c) {
        if (c >= 'A' && c <= 'Z')
            return c - 'A' + 26;
        return c - 'a';
    }

    string minWindow(string s, string t) {

        vector<int> f1(52, 0), f2(52, 0);

        int n = s.size(), m = t.size();

        if (m > n) return "";

        for (char c : t)
            f1[idx(c)]++;

        int h = -1, tl = 0;

        int ans = INT_MAX;
        int l = -1;

        while (true) {

            bool expanded = false;
            bool shrunk = false;

            // Expand
            while (h + 1 < n && !valid(f1, f2)) {
                h++;
                f2[idx(s[h])]++;
                expanded = true;
            }

            // Shrink
            while (tl <= h && valid(f1, f2)) {

                if (h - tl + 1 < ans) {
                    ans = h - tl + 1;
                    l = tl;
                }

                f2[idx(s[tl])]--;
                tl++;
                shrunk = true;
            }

            if (!expanded && !shrunk)
                break;
        }

        if (l == -1) return "";

        return s.substr(l, ans);
    }
};