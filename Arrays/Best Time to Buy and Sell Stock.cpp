// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int maxP = 0;
//         for(int i =0; i<prices.size(); i++){
//             for(int j=i+1; j<prices.size(); j++ ){
//                 if(prices[j]-prices[i]>maxP) maxP =prices[j]-prices[i]; 
//             }
//         }
//         return maxP;
//     }

// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int mini = prices[0];
        for(int i =1; i<prices.size(); i++){
            int cost = prices[i]-mini;
            maxP = max(maxP,cost);
            mini = min(mini, prices[i]);
        }
        return maxP;
    }

};
