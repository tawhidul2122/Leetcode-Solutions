// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end(),
            [](vector<int>& a, vector<int>& b){
                return a[1] < b[1];
            });
        
        int discarded = 0;
        int last_end = INT_MIN;
        
        for(vector<int> interval : intervals){
            if(last_end > interval[0])
                ++discarded;
            else
                last_end = interval[1];
        }
        
        return discarded;
    }
};