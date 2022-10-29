class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> august; 
        for (int i = 0; i < plantTime.size(); ++i) 
            august.emplace_back(plantTime[i], growTime[i]); 
        
        sort(august.begin(), august.end(), [&](auto& lhs, auto& rhs) {return lhs.second > rhs.second;}); 
        
        int ans = 0; 
        for (int i = 0, prefix = 0; i < august.size(); ++i) {
            prefix += august[i].first; 
            ans = max(ans, prefix + august[i].second); 
        }
        return ans; 
        
    }
};
