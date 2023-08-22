// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero


class DSU{
public:
    vector<int> parent;
    
    DSU(int N){
        parent = vector<int>(N);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(parent[x] != x){ //initial state
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y){
        parent[find(x)] = find(y);
    }
};

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int ans = 0;
        
        vector<bool> visited(connections.size(), false);
        
        while(any_of(visited.begin(), visited.end(), [](const bool& b){return !b;})){
            for(int i = 0; i < connections.size(); i++){
                if(visited[i]) continue;
                vector<int> conn = connections[i];
                if(dsu.parent[conn[0]] == 0){
                    dsu.unite(conn[1], conn[0]);
                    ans++;
                    visited[i] = true;
                }else if(dsu.parent[conn[1]] == 0){
                    dsu.unite(conn[0], conn[1]);  
                    visited[i] = true; 
                }
            }
        }
        
         
        
        return ans;
    }
};