class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map <int, int> m;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        priority_queue <pair<int, int>> p;
        for(auto x : m){
            p.push({x.second, x.first});
        }   
        vector <int> v;
        while(k){
            v.push_back(p.top().second);
            p.pop();
            k--;
        }    
        return v; 
    }
};
