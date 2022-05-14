# Final Project Grade

Awesome work, everyone! I hope it was a rewarding experience for you all :D

Here are some parts of the final project grade (apart from contract, proposal, and midproject checkin).

If you would like to showcase your work, feel free to clone this repository and host it on your personal git account (github-dev.cs.illinois.edu is being retired soon).

## Development Log

### Grade 

Sophisticated (100%)

Development Log (5 pts)
- [x] >= 4 development logs

### Comments

______________________________________________________________

## Presentation
### Content Grade

Sophisticated (100%)

Final Presentation Content (10 pts)
- [x] A short summary of the goals set for the project and a statement of whether the goals were met.
- [x] Some highlights of the development process (dataset, major design choices, and testing)
- [x] Results of each method
- [x] Concluding thoughts (what was learned and what you would do next)

### Skills Grade

Sophisticated (100%)

Final Presentation Skills (5 pts)
- [x] Roughly equal responsibilities
- [x] Appropriate and understandable visual aids

### Comments

Easy-to-follow demo and concise summary of the project. Glad the curse of demo didn't kick in. The fact that ATL is the most important airport is surprising to me. Do you have some guess why it is so? To improve further, the presentation could use some visualizations along with some descriptions.


______________________________________________________________

## Written Report
### Grade

Sophisticated (100%)

Written Report (5 pts)
- [x] There are clear descriptions, figures, or tables of each method's output on the full target dataset.
- [x] Projects findings

### Comments

The report contains all components and offers some insights into their development processes.

## README

### Grade

Sophisticated (100%)

Readme (5 pts)
- [x] The linkage and location of all major code, data, results, and deliverable files
- [x] The necessary commands to run the assignment, include instructions for selecting the input dataset and output location
- [x] Instructions on how to reproduce the tests

### Comments

The readme contains some information in all required categories, but could be improved. For example, introducing the project for readers with no background, structuring locations to be more navigatable, showcasing the `main` product with concrete runs. 


______________________________________________________________

## Code

### Goals Grade

Sophisticated (100%)

Code Goals (30 pts)
- [x] All methods listed in goals were successfully developed
- [x] All algorithms can be run on the full target dataset
- [x] All algorithms are thoroughly tested

### Execution Grade

Sophisticated (100%)

Code Execution (5 pts)
- [x] All methods and tests can be run
- [x] Ability to alter or adjust the input data and output location

### Efficiency Grade

Partly Competent (80%)

Code Efficiency (5 pts)
- [ ] Code adheres to the expected Big O (Dijkstra's)
- [ ] There is no obvious inefficiency
- [x] Complete on target datasets

### Organization Grade

Partly Competent (80%)

Code Organization (5 pts)
- [ ] Code is human-readable
- [ ] Unnecessary or obsolete code is completely absent

### Comments

Overall good implementation of the algorithms. Fairly well-partitioned methods with helper functions when appropriate. Creative use of BFS and interpretation (layovers) specifically on flight dataset.

In general, we would like to see more tests (though I didn't deduct point). Some test cases are hard to be verified by hand, especially those that asserts with floating points. Synthesizing location with trivial (but not neccessarily actual) coordinates could help with the testing process.

The proposal proposes a `O((|V| + |E|) log |V|)` Dijkstra's but the implementation seems to be `O((|V|^2 + |E|) log |V|)`. The problematic part is how the next closest node `minID` is selected. The method iterates over the ordered map, incurring `O(log |V|)` for each iteration and so `O(|V| log |V|)` per `minID(...)`. In total, the part accumulates to `O(|V|^2 log |V|)`. To fix this, recommend using a heap data structure to quickly get the next `minID`, e.g. by using `priority_queue`.

Code organization is a bit raw to read. We would like to see more user-facing comments on `*.h` and developer-facing comments on `*.cpp`. Some parts are difficult to understand without a proper background. There are also some unused code present in the repository such as `Colorspace`, `PNG.*`, `LUVAPixel.*`, `RGB_LUVV.h`. Directory hierarchy could be tidied a bit better.
