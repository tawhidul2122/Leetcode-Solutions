// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int sellOne = 0;
    int holdOne = INT_MIN;

    for (const int price : prices) {
      sellOne = max(sellOne, holdOne + price);
      holdOne = max(holdOne, -price);
    }

    return sellOne;
  }
};
