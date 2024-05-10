#include <iostream>
#include <vector>

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;


TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph, false);
    CHECK(ariel::Algorithms::isConnected(g) == "The graph is connected.");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2, false);
    CHECK(ariel::Algorithms::isConnected(g) == "The graph is not connected.");

    vector<vector<int>> graph3 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph3, false);
    CHECK(ariel::Algorithms::isConnected(g) == "The graph is connected.");

    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph4, false);
    CHECK(ariel::Algorithms::isConnected(g) == "The graph is not connected.");

    vector<vector<int>> graph5 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};
    g.loadGraph(graph5, true);
    CHECK(ariel::Algorithms::isConnected(g) == "The graph is strongly connected.");

    vector<vector<int>> graph6 = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 0, 0}};
    g.loadGraph(graph6, true);
    CHECK(ariel::Algorithms::isConnected(g) == "The graph is weakly connected.");
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph, false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2, false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "There is no path from 0 to 4");

    vector<vector<int>> graph3 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph3, false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->2");

    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph4, false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "There is no path from 0 to 2");

    vector<vector<int>> graph5 = {
        {0, -2, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph5, true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "The graph contains a negative cycle.");

    vector<vector<int>> graph6 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph6, false);
    CHECK(ariel::Algorithms::shortestPath(g, 3, 2) == "");

    vector<vector<int>> graph8;
    g.loadGraph(graph8, false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "");

    vector<vector<int>> graph9 = {
            {0, 1, 0, 0, 0},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
    g.loadGraph(graph9, false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "There is no path from 0 to 3");

}

TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph, false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2, false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph4, false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph5 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};
    g.loadGraph(graph5, true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph6 = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 0, 0}};
    g.loadGraph(graph6, true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph7 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph7, false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph8 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph8, false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph9;
    g.loadGraph(graph9, false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph, false);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2, false);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is not bipartite");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3, false);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");

    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph4, false);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph5 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph5, false);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is not bipartite");   

    vector<vector<int>> graph6;
    g.loadGraph(graph6, false);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={}, B={}"); 
}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph, false));

    vector<vector<int>> graph2 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0},
        {0, 0, 4},
        {0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph2, false));

    vector<vector<int>> graph3 = {
        {0, 1, 2, 2, 2, 2, 2},
        {2, 3, 4, 5, 6, 0, 7},
        {2, 3, 4, 5, 6, 7, 0}};
    CHECK_THROWS(g.loadGraph(graph3, false));

}

TEST_CASE("Test negativeCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}};
    g.loadGraph(graph, false);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph does not contain any negative weights.");


    vector<vector<int>> graph2 = {
        {0, 1, 2},
        {1, 0, -4},
        {2, -4, 0}};
    g.loadGraph(graph2, false);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph contains a negative cycle.");

    vector<vector<int>> graph4 = {
        {0, 1, 2},
        {1, 0, -3},
        {2, -3, 0}};
    g.loadGraph(graph4, true);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph contains a negative cycle.");

    vector<vector<int>> graph5;
    g.loadGraph(graph5, false);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph is empty.");
}