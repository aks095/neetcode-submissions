// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         deque <int> d;
//         int n = prices.size();
//         int ans = 0;
//         for(int i = 0; i < n; i++){
//             if(!d.empty()){
//                 if(d.back() >= prices[i]){
//                     ans = max(d.front()-d.back(), ans);
//                     while(!d.empty() && d.back() >= prices[i]){
//                         d.pop_back();
//                     }
//                     d.push_back(prices[i]);
//                 }
//                 else d.push_back(prices[i]);
//             }
//             else d.push_back(prices[i]);
//         }

//         if(!d.empty()){
//             ans = max(d.back()-d.front(), ans);
//         }

//         return ans;
//     }
// };
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        deque<int> d;
        int n = prices.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            if(!d.empty()){
                // 1. Calculate the potential profit if we sold at today's price
                ans = max(prices[i] - d.front(), ans);
                
                // 2. If the current price drops, maintain the monotonic property
                if(d.back() >= prices[i]){
                    while(!d.empty() && d.back() >= prices[i]){
                        d.pop_back();
                    }
                }
                d.push_back(prices[i]);
            }
            else {
                d.push_back(prices[i]);
            }
        }

        return ans;
    }
};