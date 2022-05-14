#include "Node.h"
#include <iostream>
// # define M_PI           3.14159265358979323846
Node::Node() {

}

Node::Node(int ID, string name, string city, string country, double latitude, double longitude) {
    name_ = name;
    city_ = city;
    country_ = country;
    latitude_ = latitude;
    longitude_ = longitude;
    ID_ = ID;
}

string Node::getName() {
    return name_;
}

string Node::getCity() {
    return city_;
}

string Node::getCountry() {
    return country_;
}

double Node::getLatitude() {
    return latitude_;
}

double Node::getLongitude() {
    return longitude_;
}

int Node::getID() {
    return ID_;
}

void Node::addEdge(Edge* edge) {
    edges_.push_back(edge);
    // if (startEdge_ == nullptr) {
        // startEdge_ = edge;
        // return;
    // }
    // Edge* curr = startEdge_;
    // while (curr->getNextEdge() != nullptr) {
        // curr = curr->getNextEdge();
    // }
    // curr->setNextEdge(edge);
}


Edge* Node::getEdge(Node* n2) {
    for (unsigned int i = 0 ; i < edges_.size(); i++) {
        if (edges_.at(i)->getDestNode() == n2->getID()) {
            return edges_.at(i);
        }
    }
    return nullptr;
}

vector<Edge*> Node::getEdges() {
    return edges_;
}
