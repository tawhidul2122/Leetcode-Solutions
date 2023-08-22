// https://leetcode.com/problems/find-numbers-with-even-number-of-digits

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        int selfCount=0;
        for(int i=0;i<nums.size();i++){
            while(nums[i]>0){
                nums[i]=nums[i]/10;
                selfCount++;
                
            }
            if(selfCount%2==0) count++;
    }
        return count;
    }
        
};