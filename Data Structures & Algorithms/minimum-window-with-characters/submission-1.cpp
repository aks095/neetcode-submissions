class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size()) return "";

        vector<int> freq(128, 0);

        // Frequency of characters needed
        for (char c : t)
            freq[c]++;

        int left = 0;
        int right = 0;
        int required = t.size();

        int start = 0;
        int minLen = INT_MAX;

        while (right < s.size()) {

            // Include current character
            if (freq[s[right]] > 0)
                required--;

            freq[s[right]]--;

            right++;

            // Window is valid
            while (required == 0) {

                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                freq[s[left]]++;

                if (freq[s[left]] > 0)
                    required++;

                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};