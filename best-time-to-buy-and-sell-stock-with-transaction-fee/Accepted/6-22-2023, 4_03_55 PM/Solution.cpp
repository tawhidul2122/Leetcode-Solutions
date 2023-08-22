// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int hold = INT_MIN, empty = 0;
        int newhold;
        
        for(int i = 1; i <= n; i++){
            newhold = max(hold, empty-prices[i-1]-fee);
            empty = max(empty, hold+prices[i-1]);
            hold = newhold;
        }
        
        return max(hold, empty);
    }
};