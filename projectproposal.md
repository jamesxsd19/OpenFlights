# CS 225 Project Proposal



#    Leading Question

The main goal of our project is to determine which airports are most important or most heavily traveled using the OpenFlights dataset containing all of the flights from around the world.  We aim to utilize Dijkstra's algorithm to find the shortest path between two destinations, and utilize a PageRank algorithm to find the airports with the greatest traffic. 

## Dataset Acquisition and Processing

We are using the OpenFlights dataset. Their data is stored in airports.dat and routes.dat, and we will be reading from these files to get the data. Since flights are represented by traveling from one airport to another, we can treat each airport as its own node in a directed graph. We’re planning on calculating the distance between each airport and then using that distance to assign a weight to each of the edges. We can use this graph with the weighted edges to create a 2d array / matrix to store all of this data. Once we’ve converted the data to this form, we can begin using it in our graph algorithms. 

## Graph Algorithms

We will focus on algorithms for two main tasks- finding the shortest path and determining which airports are most important. In particular, for shortest path, the most commonly used algorithm is Djikstra’s. We will specifically use this algorithm to find which airports given a set of inputs are the most important. For the format of inputs, we would need pairwise distances between different airports, which likely won’t include all possible pairs because the purpose of the algorithm is to find lowest distance given not all vertices share an edge. This could come in several ways, for example as a two dimensional array or vector and an index or list of indices that we want to find the shortest path in between. It could also come in as a vector of pairs, where the pairs are indices for the airports or some other form of unique identification for each. For the theory behind Djikstra’s, we would for a given node use a breadth-first-search to find the shortest distance to another given node, or simply for all other nodes. This doesn’t need a heuristic as we have the explicit distances between each airport to serve as the scoring function for which nodes are closer or farther. The output of this algorithm depends on the task, but if we pass in two nodes to find their closest distance it would simply be the scalar numeric value. Otherwise, it could be a two dimensional array or vector of pairwise closest distances. If we have a set source node, as the Djikstra’s algorithm is defined, the time complexity given E as number of edges and V as number of vertices is log V * (E + V), and the space complexity is (E + V).

For the other task of identifying most important airports, we plan on developing a heuristic for the importance of airport based of its connections and those connections’ traffic. In particular, for assessing airport A, if it’s connected to airport B and is the only connection B has or amongst the most dominant ones (as measured by traffic), then that would give it high importance. We can thus develop heuristics that aggregate this for nodes of airport A and produce what the relative importance of A is. Doing this across all airports would provide a solid manner of comparison as well as an absolute ranking. The inputs for this would be an adjacency matrix between airports, as well as a one-dimensional vector/array of traffic as is provided by the data. The output would be a sorted vector/array of importances of each of the airports. This could be saved in one large vector and then used for a variety of post-algorithm purposes, varying from identifying most important airports in given set of regions aka list of lists of airports, to choosing the more important of two airports. The time complexity is O(n) for getting number of edges of each node, O(n) for getting traffic of each node, O(n) for performing any constant operations on all nodes, and O(n log n) for sorting the nodes at the end. Combined this provides a time complexity of O(n log n). The space complexity would be linearly proportional to the number of nodes, so O(n), as that is the space of what’s returned as well. 

## Timeline

**Week 1**: Create boilerplate code and research how to find the shortest distance between two nodes(airports) and how to use pageRank to determine which nodes are the most heavily trafficked

**Week 2**: Create functions to read the data in from the dataset and format the data to be able to be put into functions/algorithms

**Week 3**: Start writing the algorithms and functions to be able to determine which nodes are the most important, and how to determine the shortest path given two nodes.

**Week 4**: Finish the implementation of the algorithms and begin writing tests for all the algorithms and functions to ensure they work properly

**Week 5**: Finalize the project/fix all bugs and finalize tests for all methods and functions

**Week 6**: Finalize the project report 

