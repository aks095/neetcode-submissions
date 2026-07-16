class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector <pair<string, string>> p;
        for(int i = 0; i < n; i++){
            string s = strs[i];
            sort(s.begin(), s.end());

            p.push_back({s, strs[i]});
        }

        sort(p.begin(), p.end());

        
        vector <vector<string>> ans;
        vector <string> v;
        v.push_back(p[0].second);
        for(int i = 1; i < n; i++){
            if(p[i].first == p[i-1].first)v.push_back(p[i].second);
            else{
                ans.push_back(v);
                v.clear();
                v.push_back(p[i].second);
            }
        }
        ans.push_back(v);
        return ans;
    }
};
