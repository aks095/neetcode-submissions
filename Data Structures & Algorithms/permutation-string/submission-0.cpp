class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size()) return false;

        vector<int> cnt(26,0);

        for(char c : s1)
            cnt[c-'a']++;

        int k = s1.size();

        for(int i=0;i<k;i++)
            cnt[s2[i]-'a']--;

        if(all_of(cnt.begin(), cnt.end(), [](int x){ return x==0; }))
            return true;

        for(int i=k;i<s2.size();i++){

            cnt[s2[i]-'a']--;
            cnt[s2[i-k]-'a']++;

            if(all_of(cnt.begin(), cnt.end(), [](int x){ return x==0; }))
                return true;
        }

        return false;
    }
};