# CS 225 Project Results

#    Importance of Airports using PageRank algorithm
We had two main use-cases coming in for importance of airportance: getting the top N most important airports, for any positive integer N in appropriate range, 
and for an inputted airport determining its rank of relative importance. For example, if you requested the top 10 most important airports, you would get the 
following output:
1. Hartsfield Jackson Atlanta International Airport in Atlanta, United States
2. London Heathrow Airport in London, United Kingdom
3. Chicago O'Hare International Airport in Chicago, United States
4. John F Kennedy International Airport in New York, United States
5. Los Angeles International Airport in Los Angeles, United States
6. Charles de Gaulle International Airport in Paris, France
7. Frankfurt am Main Airport in Frankfurt, Germany
8. Dallas Fort Worth International Airport in Dallas-Fort Worth, United States
9. San Francisco International Airport in San Francisco, United States
10. Lester B. Pearson International Airport in Toronto, Canada.

Specifically, our leading question was about which airports are most important, or more specifically, most heavily traveled through around the world. 
We used the PageRank algorithm to tackle this question. Our PageRank output such as the provided sample above successfully answered this question by outputting
a vector with values corresponding to each airport's importance, indexed by the airport's ID, where the values represented relative weights of the airports. To
test the accuracy of what our algorithm found as the most important airports, we computed the eigenvector of smaller sample adjacency matrices and would run our 
algorithm on those. Since the algorithm's output should be the eigenvector that corresponds to the largest eigenvalue for the given matrix, our tests verified
whether the vectors we ourselves calculated matched with those the algorithm was outputting, up to a high level of precision. Then, to test whether an inputted 
airport had the correct relative importance outputted, we verified by running the importance ranking of all airports and then seeing which rank the airport we 
inputted was at, to make sure they were the same.

One difficulty we had with PageRank implementation was that we didn’t have data for how much routes between airports were used, so we couldn’t get weights of 
importance to use. We ended up using an unweighted adjacency list for our implementation, or in other words 0 if two airports weren’t connected and 1 if they were.
Since our output of most important airports closely resembled the ranks of airports in terms of total traffic, we learned that the number of connections an airport
has is a fairly accurate proxy of the total traffic going through that airport, which wasn’t necessarily obvious at the beginning because connections could have 
lower or higher frequency of flights.

# Djikstra's Algorithm
Djikstra's algorithm was used mainly to find the shortest path between two airports when considering the distance between airports. Contrary to BFS, Djikstra's took into account 
the "weight" of edges which was the numerical distance between two "airports", which were our Node class. We were able to find the shortest distance. For example, if we were trying to find the shortest path between Chicago Rockford International Airport to Noto Airport in Wajima, Japan we would receive the following path:

Chicago Rockford International Airport in Rockford, United States to 
McCarran International Airport in Las Vegas, United States to 
San Francisco International Airport in San Francisco, United States to 
Tokyo Haneda International Airport in Tokyo, Japan to 
Noto Airport in Wajima, Japan

We were able to test this function by drawing out weighted graphs and making our own mini-graphs to verify that Djikstra's was returning the correct path based on the shortest
weighted path. 

One challenge we faced was that the distance between two airports could not be represented by the euclidean distance, as the Earth is spherical. Hence, we utilized an algorithm known as "Haversine's algorithm" which calculated the distance between two points represented with longitude and latitude. This was difficult to test at first, but we used google search results to verify that our distance was close to what we expected.

# BFS Algorithm
In our project, we implemented a BFS algorithm that finds the shortest path between two airports in terms of number of layovers. We believed that this was a useful function to implement because often, layovers take up a considerable amount of time when you travel, so we thought it would be helpful for our project to both demonstrate the shortest distance in terms of geographical distance or layovers.

One example input for our BFS would be from Chicago O'Hare International Airport to Cochin International Airport in India. We would get the following output:

Chicago O'Hare International Airport in Chicago, United States to 
Abu Dhabi International Airport in Abu Dhabi, United Arab Emirates to 
Cochin International Airport in Kochi, India

Based on our research, we know that there are no direct flights between our source and destination airports, so our BFS is working accurately since it found a route with 1 layover, which is the minimum number of layovers for this route based on our research. We found similar routes and made these our test cases for our BFS implementation. 

One difficulty we ran into was verifying that our chosen route was actually the least amount of layovers, since there was no way we could manually go through every single route. One way we solved for this was using routes that we have previously traveled, so we already knew what route we were aiming to output for our BFS.