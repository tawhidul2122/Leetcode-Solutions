// https://leetcode.com/problems/find-numbers-with-even-number-of-digits

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if((nums[i]>9)&&(nums[i]%2==0)){
                count++;
            }
        }
        return count;
        
    }
};