#pragma once
#include <string>
#include <vector>
#include "Edge.h"
#include <cmath>

using namespace std;

class Node {
    public:
        Node();
        Node(int ID, string name, string city, string country, double latitude, double longitude);

        string getName();
        string getCity();
        string getCountry();
        double getLatitude();
        double getLongitude();
        int getID();
        void addEdge(Edge* edge);
        // void removeEdge(Edge* edge);
        Edge* getEdge(Node* n2);
        vector<Edge*> getEdges();

    private:
        string name_;
        string city_;
        string country_;
        double latitude_;
        double longitude_;
        int ID_;
        vector<Edge*> edges_;
};