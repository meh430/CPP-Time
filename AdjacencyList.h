#ifndef ADJ_H
#define ADJ_H
#include <iostream>
#include <vector>
class AdjacencyList {
    public:
        std::vector<int> adjList;
        int getVertex();
        AdjacencyList(int value) : vertex_val(value) {}
    private:
        const int vertex_val;
};
#endif