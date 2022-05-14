#pragma once
#include "Edge.h"
#include "Node.h"
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort

struct BFS_Node {
    std::vector<Node*> previous;
    int distance;
    Node* curr;
};

class Graph {
    public:
        Graph();
        void insertNode(Node* node);
        // void removeNode(Node* node);
        void insertEdge(Edge* edge);
        // void removeEdge(Edge* edge);
        vector<Edge*> incidentEdges(Node* node);
        bool areAdjacent(Node* n1, Node* n2);
        size_t getNumNodes() {
            return nodes.size();
        }
        std::vector<Node*> getLeastLayovers(Node* source, Node* destination);
        vector<int> getShortestPath(Node* source, Node* destination);
        int minID(map<int, double> dist, map<int, bool> visited);
        double distance(Node* source, Node* dest);
        Node* getNode(int n);
        vector<double> normalize(vector<double> input);
        vector<double> pagerank(double threshold, int max_iter);
        

    private:
        map<int, Node*> nodeID;
        vector<Node*> nodes;
        vector<double> rank;
        vector<double> multWithAdj(vector<double> input);
        double eigenvalue(vector<double> firstMult, vector<double> input);
        void power_iteration(double threshold, int max_iter);
};

vector<size_t> sort_indexes(const vector<double> &v);
Graph* parseGraph(string airportsData, string routesData);
