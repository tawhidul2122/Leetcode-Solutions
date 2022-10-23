class Solution {
public:
     vector<int> findErrorNums(vector<int>& nums) {
        multiset<int> m1(nums.begin(), nums.end());
       
        vector<int> v(nums.size());
        iota(v.begin(), v.end(), 1);
       
        multiset<int> m2(v.begin(), v.end());
        
        vector<int> ans(nums.size());
        
        vector<int>::iterator it = set_difference(m1.begin(), m1.end(), m2.begin(), m2.end(), ans.begin());
        
        it = set_difference(m2.begin(), m2.end(), m1.begin(), m1.end(), ans.begin()+1);
        ans.resize(2);
        return ans;
        
    }
};
