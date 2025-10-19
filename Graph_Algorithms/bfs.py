from collections import deque

def bfs(graph, start):
    """
    Performs Breadth-First Search on a graph starting from a given node.
    
    :param graph: Adjacency list representation of the graph
    :param start: Starting node
    :return: List of nodes in BFS order
    """
    visited = set()
    queue = deque([start])
    visited.add(start)
    result = []
    
    while queue:
        node = queue.popleft()
        result.append(node)
        
        for neighbor in graph.get(node, []):
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
    
    return result

# Example usage:
# graph = {
#     'A': ['B', 'C'],
#     'B': ['A', 'D', 'E'],
#     'C': ['A', 'F'],
#     'D': ['B'],
#     'E': ['B', 'F'],
#     'F': ['C', 'E']
# }
# print(bfs(graph, 'A'))  # Output: ['A', 'B', 'C', 'D', 'E', 'F']