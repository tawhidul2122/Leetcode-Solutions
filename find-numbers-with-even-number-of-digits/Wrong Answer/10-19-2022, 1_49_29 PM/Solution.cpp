// https://leetcode.com/problems/find-numbers-with-even-number-of-digits

class Solution {
public:
    
    int findNumbers(vector<int>& nums) {
        int result=0, i;
         int number=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
               
                while(nums[i]==0){
                    nums[i]=nums[i]/10;
                    number++;
                }
            }if(number%2==0){result++;}
        }
        return result;
        
    }
};