// ID: 208791996
// Email: elyasafko@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

namespace ariel
{
    class Graph
    {
    private:
        vector<vector<int>> adjacencyMatrix;
        bool direct = false;
    public:
        Graph();
        void loadGraph(vector<vector<int>> matrix, bool directed);
        bool isDirected();
        void printGraph();
        int getEdgesCount();
        size_t getVerticesCount();
        bool isWeighted();
        bool haveNegativeWeight();
        vector<int> getNeighbors(size_t vertex);
        int getWeight(size_t src, size_t dest);
        void setDirect(bool directed);
    };
}





#endif // GRAPH_HPP