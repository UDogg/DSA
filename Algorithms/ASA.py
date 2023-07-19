#A* Search Algorithm
#A heuristic search algorithm used for finding the shortest path in a graph with heuristics to guide the search.
# Pseudocode for A* Search Algorithm
import heapq

def astar(graph, start, goal, heuristic):
    open_list = [(0 + heuristic(start, goal), start)]
    came_from = {}
    g_score = {vertex: float('inf') for vertex in graph}
    g_score[start] = 0

    while open_list:
        current = heapq.heappop(open_list)[1]

        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            path.reverse()
            return path

        for neighbor, weight in graph[current].items():
            tentative_g_score = g_score[current] + weight

            if tentative_g_score < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g_score
                f_score = g_score[neighbor] + heuristic(neighbor, goal)
                heapq.heappush(open_list, (f_score, neighbor))

    raise ValueError("No path found!")
