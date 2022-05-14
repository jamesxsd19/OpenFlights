#include "../cs225/catch/catch.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>
#include "../cs225/PNG.h"
#include "../Graph.h"

using namespace cs225;
using namespace std;

double roundNum(double num) {
    double temp = num*100;
    int temp2 = temp;
    return (((double) temp2)/100);
}

double distance(vector<double> v1, vector<double> v2) {
    double total = 0.0;
    for (unsigned int i = 0; i < v1.size(); i++) {
        total += pow(v1[i] - v2[i], 2);
    }
    return pow(total, 0.5);
}


TEST_CASE("minID1", "[weight=10]")
{
    map<int, double> dist;
    map<int, bool> visited;
    dist.insert({1, 2.0});
    dist.insert({2, 3.0});
    dist.insert({4, 7.0});
    dist.insert({6, 3.0});

    Graph graph;
    REQUIRE(graph.minID(dist, visited) == 1);
    visited.insert({1, true});
    REQUIRE(graph.minID(dist, visited) == 2);
    visited.insert({2, true});
    REQUIRE(graph.minID(dist, visited) == 6);
    visited.insert({6, true});
    REQUIRE(graph.minID(dist, visited) == 4);

}

TEST_CASE("Distance1",  "[weight=10]") {

}

TEST_CASE("Djikstras Simple", "[weight=10]")
{
	Graph graph;
    Node n1(1, "JFK", "New York", "USA", 40.6413, 73.7781);
    Node n2(2, "ORD", "Chicago", "USA", 41.9803, 87.9090);
    Node n3(3, "SFA", "San Francisco", "USA", 37.6213, 122.3790);
    Node n4(4, "SEA", "Seattle", "USA", 47.6062, 122.3321);
    Node n5(5, "PEK", "Beijing", "China", 40.0799, 116.6031);
    graph.insertNode(&n1);
    graph.insertNode(&n2);
    graph.insertNode(&n3);
    graph.insertNode(&n4);
    graph.insertNode(&n5);
    Edge e1(1, 2, distance(&n1, &n2));
    graph.insertEdge(&e1);
    Edge e2(2, 3, distance(&n2, &n3));
    graph.insertEdge(&e2);
    Edge e3(3, 4, distance(&n3, &n4));
    graph.insertEdge(&e3);
    vector<int> path = graph.getShortestPath(&n1, &n2);
    vector<int> expected = {1, 2};
    REQUIRE(path == expected);
    path = graph.getShortestPath(&n1, &n3);
    expected = {1, 2, 3};
    REQUIRE(path == expected);
    path = graph.getShortestPath(&n2, &n4);
    expected = {2, 3, 4};
    REQUIRE(path == expected);
    path.clear();
    REQUIRE(graph.getShortestPath(&n1, &n5) == path);
}

TEST_CASE("Djikstras Mid", "[weight=10]")
{
	Graph graph;
    Node n1(1, "JFK", "New York", "USA", 40.6413, 73.7781);
    Node n2(2, "ORD", "Chicago", "USA", 41.9803, 87.9090);
    Node n3(3, "SFA", "San Francisco", "USA", 37.6213, 122.3790);
    Node n4(4, "SEA", "Seattle", "USA", 47.6062, 122.3321);
    Node n5(5, "PEK", "Beijing", "China", 40.0799, 116.6031);
    Node n6(6, "LHR", "London", "UK", 51.5072, 0.1276);
    graph.insertNode(&n1);
    graph.insertNode(&n2);
    graph.insertNode(&n3);
    graph.insertNode(&n4);
    graph.insertNode(&n5);
    Edge e1(1, 2, distance(&n1, &n2));
    graph.insertEdge(&e1);

    Edge e2(2, 3, distance(&n2, &n3));
    graph.insertEdge(&e2);

    Edge e3(3, 4, distance(&n3, &n4));
    graph.insertEdge(&e3);

    Edge e4(1,3, distance(&n1, &n3));
    graph.insertEdge(&e4);

    Edge e5(1, 4, distance(&n1, &n4));
    graph.insertEdge(&e5);
    vector<int> path = graph.getShortestPath(&n1, &n4);
    vector<int> expected = {1, 4};
    REQUIRE(path == expected);

    path = graph.getShortestPath(&n1, &n3);
    expected = {1, 3};
    REQUIRE(path == expected);

    path = graph.getShortestPath(&n1, &n6);
    expected = {};
    REQUIRE(path == expected);

    path = graph.getShortestPath(&n1, &n6);
    expected = {};
    REQUIRE(path == expected);

}

TEST_CASE("Test Distance", "[weight=10]")
{
	Graph graph;
    Node n1(1, "JFK", "New York", "USA", 40.6413, 73.7781);
    Node n2(2, "ORD", "Chicago", "USA", 41.9803, 87.9090);
    Node n3(3, "SFA", "San Francisco", "USA", 37.6213, 122.3790);
    Node n4(4, "SEA", "Seattle", "USA", 47.6062, 122.3321);
    Node n5(5, "PEK", "Beijing", "China", 40.0799, 116.6031);
    Node n6(6, "LHR", "London", "UK", 51.5072, 0.1276);
    graph.insertNode(&n1);
    graph.insertNode(&n2);
    graph.insertNode(&n3);
    graph.insertNode(&n4);
    graph.insertNode(&n5);

    REQUIRE(roundNum(graph.distance(&n1, &n2)) == 1188.22);
    REQUIRE(roundNum(graph.distance(&n2, &n3)) == 2963.85);
    REQUIRE(roundNum(graph.distance(&n3, &n4)) == 1110.27);
    REQUIRE(roundNum(graph.distance(&n1, &n4)) == 3886.22);
    REQUIRE(roundNum(graph.distance(&n1, &n3)) == 4152.06);
    REQUIRE(roundNum(graph.distance(&n2, &n4)) == 2763.12);


}

TEST_CASE("Easy Power Iteration", "[weight=10]") {
    Graph graph;
    Node n0(0, "JFK", "New York", "USA", 40.6413, 73.7781);
    Node n1(1, "ORD", "Chicago", "USA", 41.9803, 87.9090);
    Node n2(2, "SFA", "San Francisco", "USA", 37.6213, 122.3790);
    Node n3(3, "SEA", "Seattle", "USA", 47.6062, 122.3321);

    graph.insertNode(&n0);
    graph.insertNode(&n1);
    graph.insertNode(&n2);
    graph.insertNode(&n3);
    Edge e1(0, 1, distance(&n0, &n1));
    graph.insertEdge(&e1);

    Edge e2(0, 2, distance(&n0, &n2));
    graph.insertEdge(&e2);

    Edge e3(1, 0, distance(&n1, &n0));
    graph.insertEdge(&e3);

    Edge e4(1, 3, distance(&n1, &n3));
    graph.insertEdge(&e4);

    Edge e5(2, 0, distance(&n2, &n0));
    graph.insertEdge(&e5);

    Edge e6(2, 1, distance(&n2, &n1));
    graph.insertEdge(&e6);

    Edge e7(3, 1, distance(&n3, &n1));
    graph.insertEdge(&e7);

    Edge e8(3, 2, distance(&n3, &n2));
    graph.insertEdge(&e8);

    std::vector<double> pagerank = graph.pagerank(0.001, 1000);
    std::vector<double> solution = {1.0, 1.0, 1.0, 1.0};
    REQUIRE(pagerank == graph.normalize(solution));
}

TEST_CASE("Hard Power Iteration", "[weight=10]") {
    Graph graph;
    Node n0(0, "JFK", "New York", "USA", 40.6413, 73.7781);
    Node n1(1, "ORD", "Chicago", "USA", 41.9803, 87.9090);
    Node n2(2, "SFA", "San Francisco", "USA", 37.6213, 122.3790);
    Node n3(3, "SEA", "Seattle", "USA", 47.6062, 122.3321);
    Node n4(4, "PEK", "Beijing", "China", 40.0799, 116.6031);

    graph.insertNode(&n0);
    graph.insertNode(&n1);
    graph.insertNode(&n2);
    graph.insertNode(&n3);
    graph.insertNode(&n4);
    Edge e01(0, 1, distance(&n0, &n1));
    graph.insertEdge(&e01);

    Edge e02(0, 2, distance(&n0, &n2));
    graph.insertEdge(&e02);

    Edge e04(0, 4, distance(&n0, &n4));
    graph.insertEdge(&e04);

    Edge e12(1, 2, distance(&n1, &n2));
    graph.insertEdge(&e12);

    Edge e14(1, 4, distance(&n1, &n4));
    graph.insertEdge(&e14);

    Edge e20(2, 0, distance(&n2, &n0));
    graph.insertEdge(&e20);

    Edge e24(2, 4, distance(&n2, &n4));
    graph.insertEdge(&e24);

    Edge e30(3, 0, distance(&n3, &n0));
    graph.insertEdge(&e30);

    Edge e31(3, 1, distance(&n3, &n1));
    graph.insertEdge(&e31);

    Edge e32(3, 2, distance(&n3, &n2));
    graph.insertEdge(&e32);

    Edge e34(3, 4, distance(&n3, &n4));
    graph.insertEdge(&e34);

    Edge e41(4, 1, distance(&n4, &n1));
    graph.insertEdge(&e41);

    Edge e43(4, 3, distance(&n4, &n3));
    graph.insertEdge(&e43);

    vector<double> pagerank = graph.pagerank(0.001, 1000);
    vector<double> solution = {1.124, 0.792, 0.890, 1.595, 1};  
    REQUIRE(distance(pagerank, graph.normalize(solution)) <= 0.01);
}

TEST_CASE("Data Parser", "[weight=10]") {
    Graph* graph = parseGraph("./tests/testairports.csv", "./tests/testroutes.csv");
    Node* n0 = graph->getNode(0);
    Node* n3 = graph->getNode(3);
    REQUIRE(graph->getNumNodes() == 6);
    REQUIRE(graph->areAdjacent(n0, n3));
    REQUIRE(!graph->areAdjacent(n3, n0));
    REQUIRE(n0->getEdges().size() == 1);
    REQUIRE(n3->getEdges().size() == 0);
}

TEST_CASE("BFS", "[weight=10]") {
    Graph graph;
    Node n0(0, "JFK", "New York", "USA", 40.6413, 73.7781);
    Node n1(1, "ORD", "Chicago", "USA", 41.9803, 87.9090);
    Node n2(2, "SFA", "San Francisco", "USA", 37.6213, 122.3790);
    Node n3(3, "SEA", "Seattle", "USA", 47.6062, 122.3321);
    Node n4(4, "PEK", "Beijing", "China", 40.0799, 116.6031);

    graph.insertNode(&n0);
    graph.insertNode(&n1);
    graph.insertNode(&n2);
    graph.insertNode(&n3);
    graph.insertNode(&n4);
    Edge e01(0, 1, distance(&n0, &n1));
    graph.insertEdge(&e01);

    Edge e12(1, 2, distance(&n1, &n2));
    graph.insertEdge(&e12);

    Edge e23(2, 3, distance(&n2, &n3));
    graph.insertEdge(&e23);

    Edge e30(3, 0, distance(&n3, &n0));
    graph.insertEdge(&e30);

    Edge e31(3, 1, distance(&n3, &n1));
    graph.insertEdge(&e31);

    Edge e32(3, 2, distance(&n3, &n2));
    graph.insertEdge(&e32);

    Edge e34(3, 4, distance(&n3, &n4));
    graph.insertEdge(&e34);

    Edge e41(4, 1, distance(&n4, &n1));
    graph.insertEdge(&e41);

    Edge e43(4, 3, distance(&n4, &n3));
    graph.insertEdge(&e43);

    REQUIRE(graph.getLeastLayovers(&n0, &n2).size() == 3);
    REQUIRE(graph.getLeastLayovers(&n0, &n4).size() == 5);
}