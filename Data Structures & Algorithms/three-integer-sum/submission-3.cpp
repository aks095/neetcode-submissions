class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int target = 0;
        vector <vector <int>> v;
        for(int i = 0; i < n; i++){
            if(((i != 0) && (nums[i] == nums[i-1])) || (i > (n-3)))continue;

            int j = i+1;
            int k = n-1;

            while(j < k){
                if(nums[k]+nums[j]+nums[i] > target) {
                    k--;
                    
                }
                else if(nums[k]+nums[j]+nums[i] < target){
                    j++;
                    
                }
                else {
                    v.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while((j < n) && (nums[j] == nums[j-1]))j++;
                    k--;
                    while((k >= 0) && (nums[k] == nums[k+1]))k--;
                }
            }
            
        }

        return v;

    }
};
