// ID: 208791996
// Email: elyasafko@gmail.com

#include "Graph.hpp"


namespace ariel
{
    Graph::Graph() 
    {
        // needed?
    }

    void Graph::loadGraph(vector<vector<int>> graph, bool directed) 
    {
        int numRows = graph.size();
        for (const auto& row : graph) // Check if the matrix is square
        {
            if (row.size() != numRows) 
            {
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }
        for (size_t i = 0; i < numRows; i++) // Check if the graph has a self loop
        {
            if (graph[i][i] != 0) 
            {
                throw invalid_argument("Invalid graph: The graph has a self loop.");
            }
        }
        // Load the graph to the object
        adjacencyMatrix = graph;
        direct = directed; // set the direct flag
    }
    
    void Graph::printGraph()
    {
        // Print the number of vertices and edges in the graph
        cout << "Graph with " << adjacencyMatrix.size() << " vertices and " << getEdgesCount() << " edges." << endl;
    }

    int Graph::getEdgesCount()
    {
        // Count the number of edges in the graph
        int count = 0;

        if (direct) // if directed need to check all the matrix
        {
            for (size_t i = 0; i < adjacencyMatrix.size(); i++)
            {
                for (size_t j = 0; j < adjacencyMatrix[i].size(); j++)
                {
                    if (adjacencyMatrix[i][j] != 0)
                    {
                        count++;
                    }
                }
            }
        }
        else // if not directed need to check only the upper triangle of the matrix
        {
            for (size_t i = 0; i < adjacencyMatrix.size(); i++)
            {
                for (size_t j = i; j < adjacencyMatrix[i].size(); j++)
                {
                    if (adjacencyMatrix[i][j] != 0)
                    {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }

    size_t Graph::getVerticesCount()
    {
        // Return the number of vertices in the graph
        return adjacencyMatrix.size();
    }

    bool Graph::isWeighted()
    {
        for (size_t i = 0; i < adjacencyMatrix.size(); i++)
        {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); j++)
            {
                if (adjacencyMatrix[i][j] > 1 || adjacencyMatrix[i][j] < -1)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool Graph::haveNegativeWeight()
    {
        for (size_t i = 0; i < adjacencyMatrix.size(); i++)
        {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); j++)
            {
                if (adjacencyMatrix[i][j] < 0)
                {
                    return true;
                }
            }
        }
        return false;
    }

    vector<int> Graph::getNeighbors(size_t vertex)
    {
        vector<int> neighbors;
        for (size_t i = 0; i < adjacencyMatrix[vertex].size(); i++)
        {
            if (adjacencyMatrix[vertex][i] != 0)
            {
                neighbors.push_back(i);
            }
        }
        return neighbors;
    }

    bool Graph::isDirected() 
    {
        return direct;
    }
    
    int Graph::getWeight(size_t src, size_t dest)
    {
        if (src >= adjacencyMatrix.size() || dest >= adjacencyMatrix[src].size()) {
            // Handle out-of-bounds access
            return INT_MAX;
        }
        return adjacencyMatrix[src][dest];
    }

    void Graph::setDirect(bool directed)
    {
        direct = directed;
        for (size_t i = 0; i < adjacencyMatrix.size(); i++)
        {
            for (size_t j = i; j < adjacencyMatrix[i].size(); j++)
            {
                if (!directed) // if not directed need to make the matrix symmetric
                {
                    if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i])
                    {
                        if (adjacencyMatrix[i][j] == 0)
                        {
                            adjacencyMatrix[i][j] = adjacencyMatrix[j][i];
                        }
                        else if (adjacencyMatrix[j][i] == 0)
                        {
                            adjacencyMatrix[j][i] = adjacencyMatrix[i][j];
                        }
                        else
                        {
                            throw invalid_argument("Invalid graph: The graph is not symmetric.");
                        }
                    }
                }
            }
        }
    }
} 

