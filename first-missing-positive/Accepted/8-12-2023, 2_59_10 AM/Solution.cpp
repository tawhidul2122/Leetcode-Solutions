// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> unums;
        
        for(int& num : nums){
            if(num > 0){
                unums.insert(num);
            }
        }
        
        if(unums.size() == 0){
            return 1;
        }
        
        vector<int> vnums(unums.begin(), unums.end());
        
        sort(vnums.begin(), vnums.end());
        
        if(vnums[0] > 1){
            return 1;
        }
        
        for(int i = 0; i < vnums.size(); ++i){
            if(vnums[i] != i+1){
                return i+1;
            }
        }
        
        return vnums.size()+1;
    }
};