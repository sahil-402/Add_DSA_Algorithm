def floyd_warshall(graph, vertices):
    """
    Floyd-Warshall algorithm for all-pairs shortest paths with path reconstruction.
    
    :param graph: Adjacency matrix, use float('inf') for no edge
    :param vertices: List of vertices
    :return: Distance matrix and next matrix for path reconstruction
    """
    n = len(vertices)
    dist = [[float('inf')] * n for _ in range(n)]
    next_node = [[None] * n for _ in range(n)]
    
    # Initialize
    for i in range(n):
        dist[i][i] = 0
        for j in range(n):
            if graph[i][j] != float('inf'):
                dist[i][j] = graph[i][j]
                next_node[i][j] = j
    
    # Floyd-Warshall
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
                    next_node[i][j] = next_node[i][k]
    
    return dist, next_node

def reconstruct_path(next_node, start, end, vertices):
    """
    Reconstruct the path from start to end using the next_node matrix.
    
    :param next_node: Next node matrix from Floyd-Warshall
    :param start: Starting vertex index
    :param end: Ending vertex index
    :param vertices: List of vertices
    :return: List of vertices in the path
    """
    if next_node[start][end] is None:
        return None
    path = [start]
    while start != end:
        start = next_node[start][end]
        path.append(start)
    return [vertices[i] for i in path]

# Example usage:
# vertices = ['A', 'B', 'C', 'D']
# graph = [
#     [0, 1, float('inf'), 4],
#     [float('inf'), 0, 2, float('inf')],
#     [float('inf'), float('inf'), 0, 1],
#     [float('inf'), float('inf'), float('inf'), 0]
# ]
# dist, next_node = floyd_warshall(graph, vertices)
# print("Distances:", dist)
# print("Path from A to D:", reconstruct_path(next_node, 0, 3, vertices))  # ['A', 'D']