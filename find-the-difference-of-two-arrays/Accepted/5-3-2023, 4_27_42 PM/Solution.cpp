// https://leetcode.com/problems/find-the-difference-of-two-arrays

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> s1;
        unordered_set<int> s2;

        for(int i = 0; i < nums1.size(); i++){
            s1.insert(nums1[i]);
        }

        for(int i = 0; i < nums2.size(); i++){
            s2.insert(nums2[i]);
        }


        vector<int> temp;

        for(int i: s1){
            if(s2.find(i) == s2.end()){
                temp.push_back(i);
            }
        }
        vector<vector<int>> res;
        res.push_back(temp);

        temp.clear();

        for(int i: s2){
            if(s1.find(i) == s1.end()){
                temp.push_back(i);
            }
        }

        res.push_back(temp);

        return res;

    }
};
