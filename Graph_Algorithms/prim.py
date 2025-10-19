import heapq

def prim(graph, start):
    """
    Prim's algorithm to find Minimum Spanning Tree using heap.
    
    :param graph: Adjacency list with weights, e.g., {0: [(1, 1), (3, 4)]}
    :param start: Starting vertex
    :return: List of edges in MST
    """
    mst = []
    visited = set()
    pq = [(0, start, -1)]  # (weight, vertex, parent)
    total_weight = 0
    
    while pq:
        weight, u, parent = heapq.heappop(pq)
        if u in visited:
            continue
        visited.add(u)
        total_weight += weight
        if parent != -1:
            mst.append((parent, u, weight))
        
        for v, w in graph.get(u, []):
            if v not in visited:
                heapq.heappush(pq, (w, v, u))
    
    return mst, total_weight

# Example usage:
# graph = {
#     0: [(1, 1), (3, 4)],
#     1: [(0, 1), (2, 2), (3, 5)],
#     2: [(1, 2), (3, 1)],
#     3: [(0, 4), (1, 5), (2, 1)]
# }
# mst, weight = prim(graph, 0)
# print("MST edges:", mst)  # [(0, 1, 1), (1, 2, 2), (2, 3, 1)]
# print("Total weight:", weight)  # 4