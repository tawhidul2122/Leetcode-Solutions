// https://leetcode.com/problems/restore-the-array

class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        int t = to_string(k).size(); //max 10
        vector<int> count(n+1, 0);
        count[0] = count[1] = 1;
        int MOD = 1e9+7;
        int ans = 0;
        
        for(int i = 1; i < n ; i++){
            for(int j = 0; j <= min(i, t-1); j++){

                string sub = s.substr(i-j, j+1);

                if(sub[0] == '0') continue;

                if(sub.size() >= 10 && s[0] != '1') continue;
                if(stoi(sub) >= 1 && stoi(sub) <= k){

                    count[i+1] = (count[i+1]%MOD)+(count[i-j]%MOD);
                }
            }
        }
        
        return count[n] % MOD;
    }
};