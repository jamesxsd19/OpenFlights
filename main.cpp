#include "Graph.h"

int main() {
    Graph* graph = parseGraph("airports.csv", "routes.csv");
    bool cont = true;

    while (cont) {
        string option;
        cout << "\nIf you are not sure what your airport ID is you can check the first column of 'airports.csv' which contains the row index starting with 0" << endl;
        cout << "\nPlease select from the following options: " << endl;
        cout << "Option 1: Find the path of shortest distance between two airports" << endl;
        cout << "Option 2: Find the most important airports" << endl;
        cout << "Option 3: Find how important a specific airport is" << endl;
        cout << "Option 4: Find the path with least amount of layovers between two airports" << endl;
        cout << "Please enter 1, 2, 3, or 4: ";
        cin >> option;
        while (option != "1" && option != "2" && option != "3" && option != "4") {
            cout << "invalid option. Please try again: ";
            cin >> option;
        }
        if (option == "1") { // Djikstras find shortest distance
            cout << "Please enter the Airport ID of your source airport: ";
            int source_airport;
            cin >> source_airport;
            Node* source = graph -> getNode(source_airport);
            while (source == nullptr) {
                cout << "That was an invalid Airport ID number. Please try again: ";
                cin >> source_airport;
                source = graph -> getNode(source_airport);
            }
            cout << "Source Airport: " << source -> getName() << " in " << source -> getCity() << ", " << source -> getCountry() << endl;


            cout << "Please enter the Airport ID of your destination airport: ";
            int destination_airport;
            cin >> destination_airport;
            Node* destination = graph -> getNode(destination_airport);
            while (destination == nullptr) {
                cout << "That was an invalid Airport ID number. Please try again: ";
                cin >> destination_airport;
                destination = graph -> getNode(destination_airport);
            }
            cout << "Destination Airport: " << destination -> getName() << " in " << destination -> getCity() << ", " << destination -> getCountry() << endl;
            vector<int> path = graph -> getShortestPath(source, destination);
            if (path.size() == 0) {
                cout << endl;
                cout << "No valid path between two airports" << endl;
                cout << endl;
            } else {
                cout << endl;
                for (size_t i = 0; i < path.size() - 1; i++) {
                    Node* curr = graph -> getNode(path.at(i));
                    cout << curr -> getName() << " in " << curr -> getCity() << ", " << curr -> getCountry() << " to " << endl;
                }
                Node* curr = graph -> getNode(path.at(path.size() -1));
                cout <<  curr -> getName() << " in " << curr -> getCity() << ", " << curr -> getCountry() << endl;
                cout << endl;
                cout << endl;
            }
        } else if (option == "2") {
            cout << "Please select how many of the top airports you'd like to see: ";
            int num;
            cin >> num; 
            while (num >= (int) graph -> getNumNodes()) {
                cout << "Tht is more than the number of airports. Please try again: ";
                cin >> num;
            }
            vector<double> rank = graph -> pagerank(0.00001, 1000);
            vector<size_t> final_rank = sort_indexes(rank);
            for (int i = 0; i < num; i++) {
                Node* n = graph->getNode((int) final_rank[i]);
                cout << i+1 << ". " << n->getName() << " in " << n->getCity() << ", " << n->getCountry() << endl;
            }
            cout << endl;
        } else if (option == "3") {
            cout << "Please enter the Airport ID of your airport: "; 
            int num;
            cin >> num; 
            while (num >= (int) graph -> getNumNodes()) {
                cout << "Tht is more than the number of airports. Please try again: ";
                cin >> num;
            }
            vector<double> rank = graph -> pagerank(0.00001, 1000);
            vector<size_t> final_rank = sort_indexes(rank);
            auto it = find(final_rank.begin(), final_rank.end(), num);
            int index = 1 + it - final_rank.begin();
            Node* n = graph->getNode(num);
            cout << n->getName() << " in " << n->getCity() << ", " << n->getCountry() << " is " << index << " out of " << graph -> getNumNodes() << " in importance" << endl;
            cout << endl; 
        } else {
            cout << "Please enter the Airport ID of your source airport: ";
            int source_airport;
            cin >> source_airport;
            Node* source = graph -> getNode(source_airport);
            while (source == nullptr) {
                cout << "That was an invalid Airport ID number. Please try again: " << endl;
                cin >> source_airport;
                source = graph -> getNode(source_airport);
            }
            cout << "Source Airport: " << source -> getName() << " in " << source -> getCity() << ", " << source -> getCountry() << endl;


            cout << "Please enter the Airport ID of your destination airport: ";
            int destination_airport;
            cin >> destination_airport;
            Node* destination = graph -> getNode(destination_airport);
            while (destination == nullptr) {
                cout << "That was an invalid Airport ID number. Please try again: " << endl;
                cin >> destination_airport;
                destination = graph -> getNode(destination_airport);
            }
            cout << "Destination Airport: " << destination -> getName() << " in " << destination -> getCity() << ", " << destination -> getCountry() << endl;
            vector<Node*> path = graph -> getLeastLayovers(source, destination);
            if (path.size() == 0) {
                cout << "No valid path between two airports" << endl;
                cout << endl;
                cout << endl;
                continue;
            }
            for (size_t i = 0; i < path.size() - 1; i++) {
                Node* curr = path.at(i);
                cout << curr -> getName() << " in " << curr -> getCity() << ", " << curr -> getCountry() << " to " << endl;
            }
            Node* curr = path.at(path.size() -1);
            cout <<  curr -> getName() << " in " << curr -> getCity() << ", " << curr -> getCountry() << endl;
            cout << endl;
            cout << endl;
            cout << "Would you like to do something else? (Y/N) " << endl;
            string done;
            cin >> done;
            if (done == "N") {
                break;
            }
        }

        cout << "Would you like to do something else? (Y/N): ";
        string done;
        cin >> done;

        while((done != "Y") && (done != "N") && (done != "y") && (done != "n")) {
            cout << "That was an invalid option. Please enter Y or N: ";
            cin >> done;
        }
        if (done == "N" || done == "n") {
            cont = false;
            break;
        } else {
            cout<<endl;
            cout<<endl;
        }
    }
}