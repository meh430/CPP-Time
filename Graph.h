#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include "AdjacencyList.h"
class Graph {
    public:
        std::vector<AdjacencyList> graph_list;
        void addEdge(int vertex, int value);
        int getMaxVertex();
        void traverse(int start);
        void dfs(int vertex, bool visited[]);
        void printGraph();
};
#endif