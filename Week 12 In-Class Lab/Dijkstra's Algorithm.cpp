#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

vector<int> mins_of_vec(vector<float> vec) { // function to return indices of all occurences of the minimum in a vector
    vector<int> indices;
    float mini = __FLT_MAX__;

    for (size_t i=0; i<vec.size(); i++) {
        mini = min(mini, vec.at(i));
    }

    for (size_t j=0; j<vec.size(); j++) {
        if (vec.at(j) == mini) {
            indices.push_back(j);
        }
    }

    return indices;
}

int minInd(vector<int> dist, vector<bool> visited, int n) { // function to get the next index which is unvisited and has lowest distance
    int min = INT_MAX;
    int min_index;

    for (int i=0; i<n; i++) {
        if (visited.at(i) == false && dist.at(i) <= min) {
            min = dist.at(i);
            min_index = i;
        }
    }

    return min_index;
}

vector<int> dijkstras(vector<vector<int>> G, int start, int n) {
    vector<int> dist(n, INT_MAX); 
    vector<bool> visited(n, false);
    dist.at(start) = 0;

    for (int i=0; i<n-1; i++) {
        int next = minInd(dist,visited,n); // we get the index of next unvisited city with least distance to be visited

        visited.at(next) = true; // we now visit that node 

        for (int j=0; j<n; j++) { // relaxation of edges
            if (!visited.at(j) && G.at(next).at(j) && dist.at(next) != INT_MAX && (dist.at(next) + G.at(next).at(j))<dist.at(j)) {
                dist.at(j) = dist.at(next) + G.at(next).at(j);
            }
        }
    }

    return dist;
}

int main() {
    vector<vector<int>> graph = {{0, 10, 0, 0, 15, 5},
                                 {10, 0, 10, 30, 0, 0},
                                 {0, 10, 0, 12, 5, 0},
                                 {0, 30, 12, 0, 0, 20},
                                 {15, 0, 5, 0, 0, 0},
                                 {5, 0, 0, 20, 0, 0}
                                };

    int source = 0;
    int n=6;
    vector<float> avg_times(n); // vector containing average times from each city to every other city

    for (int j=0; j<n; j++) {
        for (int i=0; i<n; i++) {
            if (i!=source) {
                vector<int> solution = dijkstras(graph, source, n);
                avg_times.at(j) = accumulate(solution.begin(), solution.end(), 0)/5;
                cout << "Shortest time taken to get from from city " << source << " to city " << i << " : " << solution.at(i) << endl;
            }
        }
        cout << "-----------------------------------------------------------" << endl;
        source++;   
    }

    for (int k=0; k<n; k++) {
        cout << "Average time taken to get to every other city if hospital was made at node " << k << " : " << avg_times.at(k) << endl;
    }

    cout << "-----------------------------------------------------------" << endl;

    vector<int> mins = mins_of_vec(avg_times);
    if (mins.size() == 1) {
        cout << "Hence, we must make hospital in city : " << avg_times.at(0) << endl;
    }

    else {
        cout << "Hence, we can make a hospital either in city ";
        for (size_t i=0; i<mins.size(); i++) {
            if (i != mins.size()-1 && i!=mins.size()-2) {
                cout << mins.at(i) << ", ";
            }

            else if (i == mins.size()-2) {
                cout << mins.at(i);
            }

            else if (i == mins.size()-1) {
                cout << " or " <<mins.at(i) << endl;
            }
        }
    }

}
