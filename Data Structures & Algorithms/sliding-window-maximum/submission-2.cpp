class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <pair<int, int>> d;
        int n = nums.size();
        for(int i = 0; i < k ; i++){
            while(!d.empty() && nums[i] > d.back().first){
                d.pop_back();
            }

            d.push_back({nums[i], i});
        }

        vector <int> ans;
        ans.push_back(d.front().first);
        for(int i = k; i < n; i++){
            while(!d.empty() && nums[i] > d.back().first){
                d.pop_back();
            }

            d.push_back({nums[i], i});

            while(i - d.front().second >= k)d.pop_front();


            ans.push_back(d.front().first);
        }

        return ans;


    }
};
