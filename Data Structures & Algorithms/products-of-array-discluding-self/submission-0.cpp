class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int pre[n];
        int suf[n];
        pre[0] = nums[0];
        suf[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            pre[i] = nums[i]*pre[i-1];
            suf[n-i-1] = nums[n-i-1]*suf[n-i];
        }

        vector <int> v;

        for(int i = 0; i < n; i++){
            if(i == 0){
                v.push_back(suf[1]);
            }
            else if(i == n-1){
                v.push_back(pre[n-2]);
            }
            else v.push_back(pre[i-1]*suf[i+1]);
        }

        return v;
    }
};
