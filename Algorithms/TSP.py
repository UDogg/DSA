#Travelling Salesman Problem
#A combinatorial optimization problem to find the shortest possible route that visits all given cities and returns to the starting city.
# Pseudocode for TSP using dynamic programming
def tsp_dp(graph, start):
    n = len(graph)
    all_sets = [1 << i for i in range(n)]
    dp = [[float('inf')] * n for _ in range(1 << n)]

    for mask in range(1, 1 << n):
        if mask & 1 == 0:
            continue
        for current in range(n):
            if mask & (1 << current) == 0:
                continue
            prev_mask = mask ^ (1 << current)
            if prev_mask == 0:
                dp[mask][current] = graph[start][current]
            else:
                for prev in range(n):
                    if prev_mask & (1 << prev):
                        dp[mask][current] = min(dp[mask][current], dp[prev_mask][prev] + graph[prev][current])

    final_mask = (1 << n) - 1
    min_cost = float('inf')
    for end in range(n):
        if end == start:
            continue
        min_cost = min(min_cost, dp[final_mask][end] + graph[end][start])

    return min_cost
