class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        import collections
        graph = collections.defaultdict(list)
        for i, x in enumerate(stones):
            for j in range(i+1, len(stones)):
                y = stones[j]
                if x[0] == y[0] or x[1] == y[1]:
                    graph[i].append(j)
                    graph[j].append(i)

        n = len(stones)
        res = 0
        seen = [False] * n
        for i in range(n):
            if not seen[i]:
                stack = [i]
                seen[i] = True
                while stack:
                    res += 1
                    curr = stack.pop()
                    for neighbor in graph[curr]:
                        if seen[neighbor]:
                            continue
                        stack.append(neighbor)
                        seen[neighbor] = True
                res -= 1

        return res