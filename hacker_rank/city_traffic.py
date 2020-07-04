from collections import defaultdict

def dfs(g, max_t, v, visited):
    visited[v] = True
    sum_for_parent = v
    max_from_adj = 0
    for n in g[v]:
        u = n[0]
        if u not in visited:
            s = n[1] if n[1] > 0 else dfs(g, max_t, u, visited)
            sum_for_parent+=s
            n[1] = s
            if s> max_from_adj:
                max_from_adj = s
    # print(f"v: {v} max_from_adj: {max_from_adj} sum_for_parent: {sum_for_parent}")
    # print()
    max_t[v] = max(max_t.get(v, 0), max_from_adj)
    return sum_for_parent

# max traffic in each city
def city_traffic():
    g = {1: [[5, 0]], 4: [[5, 0]], 3: [[5, 0]], 5: [[1, 0], [4, 0], [3, 0], [2, 0]],
         2: [[5, 0], [15, 0], [7, 0]], 7: [[2, 0], [8, 0]], 8: [[7, 0], [38, 0]], 15: [[2, 0]], 38: [[8, 0]]}
    max_t = {}
    for v in g.keys():
        visited = {}
        dfs(g, max_t, v, visited)

