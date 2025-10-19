def dfs_recursive(graph, node, visited=None, result=None):
    """
    Performs Depth-First Search recursively on a graph starting from a given node.
    
    :param graph: Adjacency list representation of the graph
    :param node: Current node
    :param visited: Set of visited nodes
    :param result: List to store the traversal order
    :return: List of nodes in DFS order
    """
    if visited is None:
        visited = set()
    if result is None:
        result = []
    
    visited.add(node)
    result.append(node)
    
    for neighbor in graph.get(node, []):
        if neighbor not in visited:
            dfs_recursive(graph, neighbor, visited, result)
    
    return result

def dfs_iterative(graph, start):
    """
    Performs Depth-First Search iteratively on a graph starting from a given node.
    
    :param graph: Adjacency list representation of the graph
    :param start: Starting node
    :return: List of nodes in DFS order
    """
    visited = set()
    stack = [start]
    result = []
    
    while stack:
        node = stack.pop()
        if node not in visited:
            visited.add(node)
            result.append(node)
            # Add neighbors in reverse order to maintain order
            for neighbor in reversed(graph.get(node, [])):
                if neighbor not in visited:
                    stack.append(neighbor)
    
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
# print(dfs_recursive(graph, 'A'))  # Output: ['A', 'B', 'D', 'E', 'F', 'C']
# print(dfs_iterative(graph, 'A'))  # Output: ['A', 'C', 'F', 'E', 'B', 'D']