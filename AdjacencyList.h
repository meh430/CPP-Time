#ifndef ADJ_H
#define ADJ_H
#include <iostream>
#include <vector>
class AdjacencyList {
    public:
        int getVertex();
        void addAdjValue(int adj_alue);
        std::vector<int>* getAdjList();
        AdjacencyList(int value) : vertex_val(value) {}
    private:
        const int vertex_val;
        std::vector<int> adjList;
};
#endif