Week of 4/1/22:
This week, we determined how we are delegating tasks for the following weeks of research and implementation. In addition,
we began learning the algorithms that we are planning on implementing in our project, specifically Djikstra’s and Pagerank.
Next week we plan on beginning to write the code to parse our input data, and splitting into 2 groups to finalize how we want to 
implement the algorithms we studied this week.

Week of 4/7/22:
This week, we split off into our own relegated tasks.
James: Created the Makefile, imported the cs225 files, as well as defined a Node class for the Graph, which will represent an airport.
Sai: Created an Edge class which will be used in conjuction with the Node class that James made to represent the graph of all airports and flights.
Praneet: Modified the Node and Edge classes that James and Sai had made to add adjacency list representation. Additionally almost completed the base version of the graph class to enact this adjacency list. 
Aryan: Downloaded the airports data, and used python to import the data into a pandas dataframe so that we can use it in later methods.

Week of 4/10/22:
This week:
Praneet and Aryan: Updated the graph class to reflect the adjacency list format that we would use for the Djikstra's below. Then parsed airport data and read into the c++ objects to prepare for future use.
James and Sai: Completed a rough draft of Djikstra's algorithm to find the shortest path between two airports

Week of 4/17/22:
This week:
James: Completed Unit Tests for Djikstra's algorithm as well as MinId function in Graph.cpp
Sai: Completed Unit Tests for the distance function in Node.cpp
Praneet: Completed the data parsing for airport and routes datasets, using Sai's distance function between airports to create the weights for the edges which come from routes dataset. Began tests for each one of these.

Week of 4/24/22:
This week:
James: Setup User interaction with application through command line. Completed ability for users to find shortest path (distance wise) using Djikstras.
Sai: Worked on validating inputs and fixing bugs in main, as well as styling in the terminal
Aryan: Implemented function to find the least amount of layovers to get between two airports using a BFS implementation.
Praneet: Completed the PageRank implementation with multiple tests and finished testing for both airports and routes parsing.
