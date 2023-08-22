// https://leetcode.com/problems/smallest-sufficient-team

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int counter = 0;
        for (const string& skill_name : req_skills) {
            _idx[skill_name] = counter;
            counter++;
        }

        for (const vector<string>& skills_has : people) {
            int skill = 0;
            for (const string& skill_name : skills_has) {
                auto it = _idx.find(skill_name);
                if (it == _idx.end()) {
                    continue;
                }
                skill |= 1 << (it->second);
            }
            _people.emplace_back(skill);
        }

        memset(_dp, -1, sizeof(_dp));
        memset(_choose, false, sizeof(_choose));
        dfs(0, 0, _people.size());

        vector<int> ret;
        int status = 0;
        int i = 0;
        while (status != (1 << _idx.size()) - 1 && i < _people.size()) {
            if (_choose[status][i]) {
                status |= _people[i];
                ret.emplace_back(i);
            }
            i++;
        }
        return ret;
    }

private:
    int dfs(int status, int i, int n) {
        if (_dp[status][i] != -1) {
            return _dp[status][i];
        }

        if (status == (1 << _idx.size()) - 1) {
            _dp[status][i] = 0;
            return _dp[status][i];
        }

        if (i == n) {
            _dp[status][i] = 100000;
            return _dp[status][i];
        }

        if (dfs(status | _people[i], i + 1, n) + 1 < dfs(status, i + 1, n)) {
            // choose i
            _dp[status][i] = dfs(status | _people[i], i + 1, n) + 1;
            _choose[status][i] = true;
        } else {
            // or not
            _dp[status][i] = dfs(status, i + 1, n);
            _choose[status][i] = false;
        }

        return _dp[status][i];
    }

    int         _dp[65536][61];
    bool        _choose[65536][61];
    vector<int> _people;
    unordered_map<string, int> _idx;
};