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

    // basically yaha hume do index ke beech ka max difference nikalna hai
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int mini = prices[0];
        for(int i =1; i<prices.size(); i++){
            int cost = prices[i]-mini;      // normally cost nikal liya
            maxP = max(maxP,cost);          // cost is equivalant to profit... so humne max profit nikal liya 
            mini = min(mini, prices[i]);    // and fir mini ko update kar diya. 
        }                                   //so hum usse next iteration mei use kar sake
        return maxP;
    }

};