// https://leetcode.com/problems/find-numbers-with-even-number-of-digits

class Solution {
public:
    
    int findNumbers(vector<int>& nums) {
        int digit,ans=0;
        for (int num: nums){
            digit=0;
            while(num){
                num=num/10;
                digit++;
            }
            if(digit%2==0){
                ans++;
            }
            
        }
        return ans;
    }
};