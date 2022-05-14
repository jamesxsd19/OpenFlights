#include "Graph.h"
#include <climits>
#include <iostream>
#include <cmath>
Graph::Graph(){}

void Graph::insertNode(Node* node) {
    nodes.push_back(node);
    nodeID.insert(make_pair(node->getID(), node));
}

// void Graph::removeNode(Node* node) {
    // // unfinished, need to discuss exact graph structure
    // map<int, Node*>::iterator it;
    // it = nodeID.find(node->getID());
    // nodeID.erase(it);
// }

void Graph::insertEdge(Edge* edge) {
    int source = edge->getSourceNode();
    nodeID[source]->addEdge(edge);
}

// void Graph::removeEdge(Edge* edge) {
    // int curr = edge->getCurrentNode();
    // nodeID[curr]->removeEdge(edge);
// }

// returns head of doubly linked list of incident edges
vector<Edge*> Graph::incidentEdges(Node* node) {
    return node->getEdges();
}

bool Graph::areAdjacent(Node* n1, Node* n2) {
    return !(n1->getEdge(n2) == nullptr);
}

vector<int> Graph::getShortestPath(Node* source, Node* destination) {
    // output path
    vector<int> path;

    map<int, bool> visited_map; // Maps ID to whether they are visited or not
    map<int, double> distances_map; // Maps ID to the distance from the source Node
    map<int, int> previous; // Maps ID to the previous ID in the shortest path so far

    //initializing all previous nodes to be null(-1)
    for(unsigned i =0; i<nodes.size(); i++) {
        previous[nodes.at(i) -> getID()] = -1;
    }

    //initializing visited map
    for(unsigned i =0; i<nodes.size(); i++) {
        visited_map[nodes.at(i) -> getID()] = false;
    }

    visited_map[source -> getID()] = true;
    
    //initializing initial distance vector
    for(unsigned i =0; i<nodes.size(); i++) {
        if(areAdjacent(source, nodes.at(i))) { // If edge already exists from source node to node, initialize distance
            distances_map[nodes.at(i) -> getID()] = source->getEdge(nodes.at(i))->getWeight();
            previous[nodes.at(i) -> getID()] = source -> getID();
        } else {
            distances_map[i] = INT_MAX;
        }
    }
    // Djikstra's algorithm
    int minID = source -> getID();
    while (minID != -1) { // We break out of the loop if all ID's have been looked at

        Node* currNode = nodeID[minID];
        visited_map[minID] = true;
        vector<Edge*> adjacentEdges = currNode -> getEdges();
        for (size_t i = 0; i < adjacentEdges.size(); i++) { // Check all adjacent Nodes
            Node* adjacentNode = nodeID[adjacentEdges.at(i)->getDestNode()];
            int adjacentNodeID = adjacentNode -> getID();
            if (distances_map[adjacentNodeID] > distances_map[currNode -> getID()] + adjacentEdges.at(i)->getWeight()) {
                distances_map[adjacentNodeID] = distances_map[currNode -> getID()] + adjacentEdges.at(i)->getWeight();
                previous[adjacentNodeID] = currNode -> getID();
            }
        }
        minID = this -> minID(distances_map, visited_map);
        if (minID == destination -> getID()) {
            break;
        }
    }
    if (minID == -1) {
        return path;
    }
    
    // Retrieving path
    path.insert(path.begin(), destination -> getID());
    int pathStart = previous[destination -> getID()];
    // std::cout << pathStart << std::endl;
    while (pathStart != source -> getID()) {
        path.insert(path.begin(), pathStart);
        pathStart = previous[pathStart];
    }
    path.insert(path.begin(), source -> getID());
    return path;
}

int Graph::minID(map<int, double> dist, map<int, bool> visited) {
    int minIndex = -1;
    int min = INT_MAX;

    for (auto& pair: dist) {
        if (!visited[pair.first] && dist[pair.first] < min) {
            min = dist[pair.first];
            minIndex = pair.first;
        }
    }
    return minIndex;
}

double Graph::distance(Node* source, Node* dest) {
    double lat1 = source->getLatitude();
    double lon1 = source->getLongitude();
    double lat2 = dest->getLatitude();
    double lon2 = dest->getLongitude();

    // distance between latitudes
    // and longitudes
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
 
    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;
 
    // apply formulas
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

Node* Graph::getNode(int n) {
    Node* node = nullptr;
    map<int, Node*>::iterator it = nodeID.find(n);
    if (it != nodeID.end()) {
        return it->second;
    }
    return nullptr;
}

vector<double> Graph::multWithAdj(vector<double> input) {
    vector<double> output;
    for (unsigned int i = 0; i < nodes.size(); i++) {
        double val = 0.0;
        vector<Edge*> edges = nodes[i]->getEdges();
        for (unsigned int j = 0; j < edges.size(); j++) {
            // int node = edges[j]->getDestNode();
            // double weight = edges[j]->getWeight();
            // val += weight*(input[node]);
            val += input[edges[j]->getDestNode()];
        }
        output.push_back(val);
    }
    return output;
}

vector<double> Graph::normalize(vector<double> input) {
    double frobenius = 0.0;
    for (unsigned int i = 0; i < input.size(); i++) {
        frobenius += pow(input[i], 2);
    }
    frobenius = pow(frobenius, 0.5);
    for (unsigned int i = 0; i < input.size(); i++) {
        input[i] = input[i]/frobenius;
    }
    return input;
}

double Graph::eigenvalue(vector<double> firstMult, vector<double> input){
    double total = 0.0;
    for (unsigned int i = 0; i < input.size(); i++) {
        total += input[i]*firstMult[i];
    }
    return total;
}

void Graph::power_iteration(double threshold, int max_iter) {

    // Note: change later once we know size of input matrix
    int n = (int) nodes.size();
    int d = (int) nodes.size();

    double value = 1 / sqrt(d);

    vector<double> v(d, value);
    vector<double> first = multWithAdj(v);
    double ev = Graph::eigenvalue(first, v);
    for (int i = 0; i < max_iter; i++) {
        vector<double> newV = multWithAdj(v);
        newV = normalize(newV);
        vector<double> temp = multWithAdj(newV);
        double newEv = Graph::eigenvalue(newV, temp);
        if ((ev - newEv) < threshold && (ev - newEv) > (-1 * threshold)) {
            break;
        }
        v = newV;
        ev = newEv;
    }
    rank = v;
}

vector<double> Graph::pagerank(double threshold, int max_iter) {
    if (rank.empty()) {
        power_iteration(threshold, max_iter);
    } 
    return rank;    
}

// parse the airports data into nodes and routes data into edges between those nodes, producing graph to be used 
Graph* parseGraph(string airportsData, string routesData) {
    ifstream airports (airportsData);
    ifstream routes (routesData);
    string line;
    Graph* graph = new Graph();
    map<int, int> oldToNew;
    if (airports.is_open()) {
        bool use = false;
        while (getline(airports, line)) {
            if (!use) {
                use = true;
                continue;
            }
            stringstream data(line);
            int ID;
            int originalID;
            string name;
            string city;
            string country;
            double latitude;
            double longitude;
            int count = -1;
            while (data.good()) {
                string item;
                getline(data, item, ',');
                if (count == -1) {
                    ID = stoi(item);
                } else if (count == 0) {
                    originalID = stoi(item);
                } else if (count == 1) {
                    name = item;
                } else if (count == 2) {
                    city = item;
                } else if (count == 3) {
                    country = item;
                } else if (count == 4) {
                    latitude = stod(item);
                } else if (count == 5) {
                    longitude = stod(item);
                }
                count ++;
            }
            oldToNew.insert(pair<int, int> (originalID, ID));
            Node* node = new Node(ID, name, city, country, latitude, longitude);
            graph->insertNode(node);
        }
    }
    if (routes.is_open()) {
        bool use = false;
        while (getline(routes, line)) {
            if (!use) {
                use = true;
                continue;
            }
            stringstream data(line);
            int sourceID;
            int destID;
            int count = -1;
            bool valid = true;
            while (data.good()) {
                string item;
                getline(data, item, ',');
                if (count == 0) {
                    if (item == "\\N") {
                        valid = false;
                        continue;
                    }
                    sourceID = stoi(item);
                } else if (count == 1) {
                    if (item == "\\N") {
                        valid = false;
                        continue;
                    }
                    destID = stoi(item);
                } 
                count ++;
            }
            if (valid) {
                int realSourceID = oldToNew[sourceID];
                int realDestID = oldToNew[destID];
                Node* src = graph->getNode(realSourceID);
                Node* dest = graph->getNode(realDestID);
                if (src == nullptr || dest == nullptr) {
                    continue;
                }
                double weight = graph->distance(src, dest);
                Edge* edge = new Edge(realSourceID, realDestID, weight);
                graph->insertEdge(edge);
            }
        }
    }
    return graph;
}

vector<size_t> sort_indexes(const vector<double> &v) {

  vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  stable_sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] > v[i2];});

  return idx;
}

// Returns a vector with the least layovers route, including source and destination
std::vector<Node*> Graph::getLeastLayovers(Node* source, Node* destination) {
    std::vector<Node*> firstPrev;
    BFS_Node first = {firstPrev, 0, source};

    std::queue<BFS_Node> q;
    std::set<Node*> visited;

    q.push(first);
    visited.insert(source);

    while(!q.empty()) {
        BFS_Node currNode = q.front();
        q.pop();

        if (currNode.curr == destination) {
            std::vector<Node*> ret = currNode.previous;
            ret.push_back(currNode.curr);
            return ret;
        }

        for(auto edge : currNode.curr->getEdges()) {
            Node* adjacentNode = nodeID[edge->getDestNode()];

            if (visited.find(adjacentNode) == visited.end()) {
                visited.insert(adjacentNode);

                std::vector<Node*> newPrev = currNode.previous;
                newPrev.push_back(currNode.curr);
                q.push({newPrev, currNode.distance + 1, adjacentNode});
            }
        }
    }

    return firstPrev;
}