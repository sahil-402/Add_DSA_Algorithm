def bellman_ford(graph, start, vertices):
    """
    Bellman-Ford algorithm to find shortest paths from start, detects negative cycles.
    
    :param graph: List of edges, e.g., [('A', 'B', 1), ('A', 'C', 4)]
    :param start: Starting node
    :param vertices: List of all vertices
    :return: Dictionary of shortest distances, or None if negative cycle
    """
    distances = {node: float('inf') for node in vertices}
    distances[start] = 0
    
    # Relax edges |V|-1 times
    for _ in range(len(vertices) - 1):
        for u, v, w in graph:
            if distances[u] != float('inf') and distances[u] + w < distances[v]:
                distances[v] = distances[u] + w
    
    # Check for negative cycles
    for u, v, w in graph:
        if distances[u] != float('inf') and distances[u] + w < distances[v]:
            return None  # Negative cycle detected
    
    return distances

# Example usage:
# edges = [
#     ('A', 'B', 1), ('A', 'C', 4),
#     ('B', 'C', 2), ('B', 'D', 5),
#     ('C', 'D', 1)
# ]
# vertices = ['A', 'B', 'C', 'D']
# print(bellman_ford(edges, 'A', vertices))  # Output: {'A': 0, 'B': 1, 'C': 3, 'D': 4}