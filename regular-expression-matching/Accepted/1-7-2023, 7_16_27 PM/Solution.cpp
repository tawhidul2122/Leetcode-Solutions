// https://leetcode.com/problems/regular-expression-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector(n+1, false));
        dp[m][n] = true;
        for(int i = m; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                // cout << "(" << i << ", " << j << ")" << endl;
                bool first_match = (i < m) && (p[j] == '.' || p[j] == s[i]);
                
                if(j+1 < n && p[j+1] == '*'){
                    dp[i][j] = (first_match && dp[i+1][j]) || dp[i][j+2];
                }else{
                    dp[i][j] = first_match && dp[i+1][j+1];
                }
            }
        }
        
        return dp[0][0];
    }
};