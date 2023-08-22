// https://leetcode.com/problems/top-k-frequent-elements

class valuecomparator
{
public:
    valuecomparator(){}
    bool operator() (const pair<int, int>& lhs, const pair<int, int>&rhs) const{
        return lhs.second < rhs.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counter;
        vector<int> ans;
        
        for(int e : nums){
            counter[e]++;
        }
        
        //cannot sort map!
        // sort(counter.begin(), counter.end(), 
        //      [](const pair<int, int>& a, const pair<int, int>& b){
        //          return a.second < b.second;
        // });
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, valuecomparator> pq1;

        for(auto it = counter.begin(); it != counter.end(); it++){
            pq1.push(*it);
        }

        for(int i = 0; i < k; i++){
            pair<int, int> p = pq1.top();
            ans.push_back(p.first);
            pq1.pop();
        }
        
        return ans;
    }
};
