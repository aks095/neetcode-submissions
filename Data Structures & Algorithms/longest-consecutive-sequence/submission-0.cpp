class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> s;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            s.insert(nums[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if((s.find(nums[i]-1) == s.end()) & (s.find(nums[i]) != s.end())){
                int x = nums[i]+1;
                int temp = 1;
                while(s.find(x)!=s.end()){
                    s.erase(x);
                    x++;
                    temp++;
                }
                ans = max(temp, ans);
            }
        }

        return ans;
    }
};
