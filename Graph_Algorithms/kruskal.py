class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0] * size
    
    def find(self, p):
        if self.parent[p] != p:
            self.parent[p] = self.find(self.parent[p])  # Path compression
        return self.parent[p]
    
    def union(self, p, q):
        rootP = self.find(p)
        rootQ = self.find(q)
        if rootP == rootQ:
            return False
        # Union by rank
        if self.rank[rootP] < self.rank[rootQ]:
            self.parent[rootP] = rootQ
        elif self.rank[rootP] > self.rank[rootQ]:
            self.parent[rootQ] = rootP
        else:
            self.parent[rootQ] = rootP
            self.rank[rootP] += 1
        return True

def kruskal(edges, num_vertices):
    """
    Kruskal's algorithm to find Minimum Spanning Tree.
    
    :param edges: List of (weight, u, v) tuples
    :param num_vertices: Number of vertices
    :return: List of edges in MST
    """
    edges.sort()  # Sort by weight
    uf = UnionFind(num_vertices)
    mst = []
    
    for weight, u, v in edges:
        if uf.union(u, v):
            mst.append((u, v, weight))
            if len(mst) == num_vertices - 1:
                break
    
    return mst

# Example usage:
# edges = [
#     (1, 0, 1), (4, 0, 3), (2, 1, 2), (5, 1, 3), (1, 2, 3)
# ]
# num_vertices = 4
# mst = kruskal(edges, num_vertices)
# print(mst)  # [(0, 1, 1), (2, 3, 1), (0, 3, 4)]