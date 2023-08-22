// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int j=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
  
        
            
        }
    
    
};
// public class Solution {
//     public int removeDuplicates(int[] A) {
//       if(A.length<=1) return A.length;
//       int i=1;
//       for (int j=1; j<A.length; j++){
//           if(A[j]>A[i-1]){
//               A[i]=A[j];
//               i++;
//           }
//       }
//       return i;
//     }