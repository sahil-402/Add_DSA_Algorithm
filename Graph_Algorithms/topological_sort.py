from collections import deque, defaultdict

def topological_sort_dfs(graph):
    """
    Topological sort using DFS.
    
    :param graph: Adjacency list
    :return: List of nodes in topological order, or None if cycle
    """
    visited = set()
    rec_stack = set()
    result = []
    
    def dfs(node):
        visited.add(node)
        rec_stack.add(node)
        
        for neighbor in graph.get(node, []):
            if neighbor not in visited:
                if not dfs(neighbor):
                    return False
            elif neighbor in rec_stack:
                return False  # Cycle detected
        
        rec_stack.remove(node)
        result.append(node)
        return True
    
    for node in graph:
        if node not in visited:
            if not dfs(node):
                return None
    
    result.reverse()
    return result

def topological_sort_kahn(graph, indegree):
    """
    Topological sort using Kahn's algorithm (BFS).
    
    :param graph: Adjacency list
    :param indegree: Dictionary of indegrees
    :return: List of nodes in topological order
    """
    queue = deque([node for node in indegree if indegree[node] == 0])
    result = []
    
    while queue:
        node = queue.popleft()
        result.append(node)
        
        for neighbor in graph.get(node, []):
            indegree[neighbor] -= 1
            if indegree[neighbor] == 0:
                queue.append(neighbor)
    
    if len(result) == len(indegree):
        return result
    else:
        return None  # Cycle detected

# Example usage:
# graph = {
#     'A': ['C'],
#     'B': ['C', 'D'],
#     'C': ['E'],
#     'D': ['F'],
#     'E': ['F'],
#     'F': []
# }
# indegree = {'A': 0, 'B': 0, 'C': 2, 'D': 1, 'E': 1, 'F': 2}
# print("DFS:", topological_sort_dfs(graph))  # ['B', 'A', 'D', 'C', 'E', 'F']
# print("Kahn:", topological_sort_kahn(graph, indegree))  # ['A', 'B', 'C', 'D', 'E', 'F']