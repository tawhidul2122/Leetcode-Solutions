// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=nums[i+1]){
                nums[i]=nums[i];
            }else {
                nums[i+1]='k';
            }
                if((nums[i]!='k')){
                    nums[j]=nums[i];
                    j++;
                }
            
        } return j;
               }
    
};