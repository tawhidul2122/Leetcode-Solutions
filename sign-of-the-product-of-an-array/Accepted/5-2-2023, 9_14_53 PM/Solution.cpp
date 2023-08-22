// https://leetcode.com/problems/sign-of-the-product-of-an-array

class Solution {
 public:
  int arraySign(vector<int>& nums) {
    int sign = 1;

    for (const int num : nums) {
      if (num == 0)
        return 0;
      if (num < 0)
        sign = -sign;
    }

    return sign;
  }
};