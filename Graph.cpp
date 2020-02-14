#include <iostream>
#include <vector>
#include "Graph.h"
#include "AdjacencyList.h"

//adj implementation
void AdjacencyList::addAdjValue(int adj_value) {
    this->adjList.push_back(adj_value);
}

int AdjacencyList::getVertex() {
    return vertex_val;
}

std::vector<int>* AdjacencyList::getAdjList() {
    return &adjList;
}

//graph implementation
int Graph::getMaxVertex() {
    int max = -1000000;
    for(auto &val : this->graph_list) {
        int vert = val.getVertex();
        max = max < vert ? vert : max;
    }

    return max;
}

void Graph::addEdge(int vertex, int value) {
    AdjacencyList *temp_vertex = nullptr;
    AdjacencyList *temp_value = nullptr;
    for(auto val : graph_list) {
        if(val.getVertex() == vertex) {
            temp_vertex = &val;
            break;
        }
    }

    for(auto val : graph_list) {
        if(val.getVertex() == value) {
            temp_value = &val;
            break;
        }
    }

    if(temp_vertex == nullptr) {
        temp_vertex = new AdjacencyList(vertex);
        graph_list.push_back(*temp_vertex);
    }

    if(temp_value == nullptr) {
        temp_value = new AdjacencyList(value);
        graph_list.push_back(*temp_value);
    }

    temp_vertex->addAdjValue(value);
    temp_value->addAdjValue(vertex);
}

void Graph::traverse(int start) {
    bool visited[this->getMaxVertex() + 1];
    dfs(start, visited);
}

void Graph::dfs(int vertex, bool visited[]) {
    visited[vertex] = true;
    std::cout << vertex << " -> ";
    AdjacencyList *temp = nullptr;
    for(auto &val : this->graph_list) {
        if(val.getVertex() == vertex) {
            temp = &val;
        }
    }

    for(auto &val : *temp->getAdjList()) {
        if(!visited[val]) {
            dfs(val, visited);
        }
    }
}

void Graph::printGraph() {
    for(auto &val : graph_list) {
        std::cout << "Vertex: " << val.getVertex() << " | ";
        std::vector<int> *adjList = val.getAdjList();
        for(auto adj : *adjList) {
            std::cout << adj << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    Graph graph;
    graph.addEdge(1, 2);
    graph.addEdge(1, 8);
    graph.addEdge(2, 7);
    graph.addEdge(1, 4);
    graph.printGraph();
    graph.traverse(1);
    return 0;
}