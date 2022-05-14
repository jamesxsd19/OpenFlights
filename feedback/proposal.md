### Grade

Partly Competent (80%)

### Checklist

Leading question
- [x] Question or expected result
- [ ] How the dataset and the algorithms will answer this

Dataset
- [ ] Data format
- [x] Acquire (OpenFlights)
- [x] Process
- [x] Store (2D array)
- [ ] Data correction for potential errors (missing/empty route, )

Algorithm
- [x] One graph traversal (BFS)
  - [ ] Input and output (minor)
  - [ ] Run-time efficiency (minor)
- [x] One algorithm in class (Dijkstra's)
  - [x] Input and output
  - [x] Run-time efficiency
- [x] One algorithm not in class (PageRank)
  - [x] Input and output
  - [x] Run-time efficiency (inaccurate)

Timeline
- [x] Reasonable date on every major benchmark.

### Comments

Good proposal overall. The **leading question** section is very concise but could be improved on explicitly explaining how the dataset and algorithms will answer it (refer to comments in algorithm paragraphs below).

The **dataset** section misses some details. Most of them can be answered by inspecting the actual data.
- What is the data format?
- What data error would you expect? How would you correct them?
- How do you define the distance between two coordinates? Would you consider a spherical or flat map? One edge case to consider: latitude-longitude (89.9999, 0.0) is very close to (89.9999, 180.0).

The first algorithm paragraph proposes to find important airports and proceeds to explain **Dijkstra's**. It is highly detailed and thought-provoking, leading to these comments:
- I'm a bit lost on the connection back to the main purpose. How can we go from the shortest path(s) to important airports?
- The explanation seems to imply single-pair shortest path problem (SPSP), single-source shortest path problem (SSSP), and multiple-pairs shortest path problem, where the latter two would generate many shortest paths. Which variant would we use to find important airports?
- The paragraph also lists many ways to represent the edges and likely correctly anticipates that the edges "won’t include all possible pairs." I'd recommend measuring the density/sparsity (count number of edges and compare with its possible largest value). Given this sparsity in edge set, which edge format (adjacency matrix, adjacency list) would be most efficient?

The second algorithm paragraph (**PageRank**) does a great job on connecting the heuristic and the output back to the purpose (most important airports). However, I'd like to see more algorithm details. 
- PageRank has multiple ways to compute, e.g. eigendecomposition or iterative simulation. Which variant do you plan to implement?
- Time and space complexity should be generally be larger than O(n log n) and O(n) respectively. At the very least, we need to look at all the edges, so they should involve some |E| terms. With your choice of PageRank variant, what would be its time complexity? For iterative simulation, we can decompose into 1) complexity per iteration, and 2) number of iterations until convergence (harder to analyze).

Timeline are generally reasonable as a deadline sheet for different milestones. I'd recommend starting on some of these tasks as soon as they are unblocked and working in parallel as much as possible. For example, PageRank could be tricky to implement and more tricky to test.

Please feel free to contact me if you have any further question or need clarification. Keep up the great work!
