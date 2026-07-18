class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        int n = nums.size();
        int ans = 0;
        while(i < j){
            ans = max(ans, min(nums[i], nums[j])*(j-i));

            if(nums[i] < nums[j]){
                i++;
                while(i < n && (nums[i] <= nums[i-1]))i++;
            }
            else {
                j--;
                while(j >= 0 && (nums[j] <= nums[j+1]))j--;
            }
        }

        return ans;
    }
};
