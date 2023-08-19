class UnionFind {
 public:
  UnionFind(int n) : id(n), rank(n) {
    iota(id.begin(), id.end(), 0);
  }

  void unionByRank(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return;
    if (rank[i] < rank[j]) {
      id[i] = j;
    } else if (rank[i] > rank[j]) {
      id[j] = i;
    } else {
      id[i] = j;
      ++rank[j];
    }
  }

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }

 private:
  vector<int> id;
  vector<int> rank;
};

class Solution {
 public:
  vector<vector<int>> findCriticalAndPseudoCriticalEdges(
      int n, vector<vector<int>>& edges) {
    vector<int> criticalEdges;
    vector<int> pseudoCriticalEdges;
    for (int i = 0; i < edges.size(); ++i)
      edges[i].push_back(i);
    sort(
        edges.begin(), edges.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[2] < b[2]; });

    const int mstWeight = getMSTWeight(n, edges, {}, -1);

    for (const vector<int>& edge : edges) {
      const int index = edge[3];
      if (getMSTWeight(n, edges, {}, index) > mstWeight)
        criticalEdges.push_back(index);
      else if (getMSTWeight(n, edges, edge, -1) == mstWeight)
        pseudoCriticalEdges.push_back(index);
    }

    return {criticalEdges, pseudoCriticalEdges};
  }

 private:
  int getMSTWeight(int n, const vector<vector<int>>& edges,
                   const vector<int>& firstEdge, int deletedEdgeIndex) {
    int mstWeight = 0;
    UnionFind uf(n);

    if (!firstEdge.empty()) {
      uf.unionByRank(firstEdge[0], firstEdge[1]);
      mstWeight += firstEdge[2];
    }

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int weight = edge[2];
      const int index = edge[3];
      if (index == deletedEdgeIndex)
        continue;
      if (uf.find(u) == uf.find(v))
        continue;
      uf.unionByRank(u, v);
      mstWeight += weight;
    }

    const int root = uf.find(0);
    for (int i = 0; i < n; ++i)
      if (uf.find(i) != root)
        return INT_MAX;

    return mstWeight;
  }
};
