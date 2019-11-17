from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def bfs(self, s):
        visited = [False] * len(self.graph)

        queue = []
        
        queue.append(s)
        visited[s] = True
        
        while queue:
            s = queue.pop(0)
            print(s, end=" ")

            for i in self.graph[s]:
                if visited[i] is False:
                    visited[i] = True
                    queue.append(i)
    def dfsUtil(self, v, visited):
        visited[v] = True
        print(v, end=" ")

        for i in self.graph[v]:
            if visited[i] == False:
                self.dfsUtil(i, visited)
    def dfs(self, v):
        visited = [False] * (len(self.graph))
        self.dfsUtil(v, visited)

g = Graph() 
g.addEdge(0, 1) 
g.addEdge(0, 2) 
g.addEdge(1, 2) 
g.addEdge(2, 0) 
g.addEdge(2, 3) 
g.addEdge(3, 3) 

print("Following is DFS from (starting from vertex 2)") 
g.dfs(2)