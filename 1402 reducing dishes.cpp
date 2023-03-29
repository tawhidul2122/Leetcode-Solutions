class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());
        
        int ans = 0, sum = 0, ltc = 0;
        
    
        for(int i = 0; i < satisfaction.size() && satisfaction[i] + sum > 0; i++){
  
            sum += satisfaction[i];

            ans += sum;
        }
        
        return ans;
    }
};
