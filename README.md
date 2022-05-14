# pmern2-aryann3-jamestx2-prathi3

All the files like the project proposal, team contract, makefile, main classes such as edge, node, and graph, main.cpp, as well as the csv files for data are all in the main folder for this project. The presentation video is the VideoPresentationLink file which is also in the main folder for this project.

To run the code, we first need to ensure that the docker file is running, and then we run `make` followed by `./project` in the terminal to run the project. We will first be prompted to input a number 1-4 to choose which functionality to run. Several of the options require airport IDs, which can be found in the first column of the airports.csv file. When entering airport id a number must be entered or else the code will break, and when selecting the top N airports to view, N must be less than the total number of airports. All the functionalities and outputs of our code are in the terminal. 

We created unit tests for our algorithms, djisktras, bfs, and page rank, as well as for data parsing. We created small graphs that we drew on the whiteboard in our test cases and ran these functions on them and ensure we got the right output back. We also wrote a test case to ensure our distance function was right and we used online caluclators to make sure our ouptut was right. Lastly, we computed eigenvectors of inputted matrices for verification of some cases. To build the test suite, run `make test` followed by `./test` to run the test cases.