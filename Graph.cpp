#include <iostream>
#include <vector>
#include <queue>
#include "Graph.h"
#include "AdjacencyList.h"

//adj implementation

int AdjacencyList::getVertex() {
    return this->vertex_val;
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
    for(auto &val : this->graph_list) {
        if(val.getVertex() == vertex) {
            temp_vertex = &val;
            break;
        }
    }

    for(auto &val : this->graph_list) {
        if(val.getVertex() == value) {
            temp_value = &val;
            break;
        }
    }

    if(temp_vertex == nullptr) {
        temp_vertex = new AdjacencyList(vertex);
        temp_vertex->adjList.push_back(value);

        graph_list.push_back(*temp_vertex);
    } else {
        temp_vertex->adjList.push_back(value);
    }

    if(temp_value == nullptr) {
        temp_value = new AdjacencyList(value);
        temp_value->adjList.push_back(vertex);

        graph_list.push_back(*temp_value);
    } else {
        temp_value->adjList.push_back(vertex);
    }

    //std::cout << "ver " << temp_vertex << "\n";
    //std::cout << "val "<< temp_value << "\n";

    //temp_vertex->adjList.push_back(value);
    //temp_value->adjList.push_back(vertex);
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

    for(auto &val : temp->adjList) {
        if(!visited[val]) {
            dfs(val, visited);
        }
    }
}

void Graph::bfs(int start) {
    std::cout << "\n";
    std::queue<int> bfs_queue;
    bfs_queue.push(start);
    bool visited[this->getMaxVertex() + 1];
    visited[start] = true;
    int next;
    while(!bfs_queue.empty()) {
        next = bfs_queue.front();
        std::cout << next << " -> ";
        bfs_queue.pop();
        AdjacencyList *temp = nullptr;
        for(auto &val : this->graph_list) {
            if(val.getVertex() == next) {
                temp = &val;
            }
        }

        for(auto &adj : temp->adjList) {
            if(!visited[adj]) {
                visited[adj] = true;
                bfs_queue.push(adj);
            }
        }
    }
}

void Graph::printGraph() {
    for(auto &val : graph_list) {
        std::cout << "Vertex: " << val.getVertex() << " | ";
        //std::cout << &val << "\n";
        for(auto &adj : val.adjList) {
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
    graph.bfs(1);
    return 0;
}