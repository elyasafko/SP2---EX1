# Graph Class and Algorithms

This project includes a comprehensive `Graph` class and several sophisticated graph algorithms. It is implemented in C++ and supports both directed and undirected graphs, with capabilities for handling weighted and unweighted edges.

## Graph Class

### Overview

The Graph library manages graphs represented as adjacency matrices. It supports operations such as loading graphs, printing graph details, and manipulating graph properties.

### Functions

- **Constructor: Graph()**: Initializes a new instance of the Graph class.
- **loadGraph(vector<vector<int>> graph, bool directed)**: Loads a graph from a square matrix, validating the matrix and setting the graph's directed nature.
- **printGraph()**: Outputs the number of vertices and edges in the graph.
- **getEdgesCount()**: Returns the number of edges, considering the graph's directed or undirected nature.
- **getVerticesCount()**: Returns the number of vertices, which corresponds to the dimension of the adjacency matrix.
- **isWeighted()**: Checks if the graph has any weights other than 1 or -1, indicating it is weighted.
- **haveNegativeWeight()**: Determines if any edges have negative weights.
- **getNeighbors(size_t vertex)**: Lists all vertices connected directly by an edge to the specified vertex.
- **isDirected()**: Indicates whether the graph is directed.
- **getWeight(size_t src, size_t dest)**: Retrieves the weight of the edge between specified vertices.
- **setDirect(bool directed)**: Adjusts the graph to be directed or undirected, ensuring symmetry in the adjacency matrix for undirected graphs.

## Graph Algorithms Library

### Features

#### Connectivity Functions

- **isConnected(Graph graph)**:
  - For undirected graphs, checks connectivity using DFS to ensure all nodes are reachable from any node.
  - For directed graphs, assesses strong connectivity and weak connectivity by modifying edge directionality temporarily.

#### Bipartiteness Check

- **isBipartite(Graph &graph)**:
  - Uses BFS to determine if the graph can be two-colored, which would confirm it as bipartite, and identifies the vertex sets for each color.

#### Shortest Path Algorithms

- **shortestPath(Graph graph, size_t src, size_t dest)**:
  - Finds the shortest path using Dijkstra's algorithm for non-negative weight graphs, Bellman-Ford for negative weights, and BFS for unweighted graphs.

#### Cycle Detection

- **isContainsCycle(Graph &graph)**:
  - Utilizes DFS to detect the presence of any cycles in the graph, capable of returning the path of the cycle if found.

#### Negative Cycle Detection

- **negativeCycle(Graph graph)**:
  - Employs a modified Bellman-Ford algorithm to detect negative weight cycles, crucial for accurate application of certain shortest path algorithms.

